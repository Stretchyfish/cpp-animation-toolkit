#include "animation_engine/animated_text_object.h"

anim::AnimatedTextObject::AnimatedTextObject() : AnimationObject()
{

}

anim::AnimatedTextObject::AnimatedTextObject(std::string text, int position_x, int position_y) : AnimationObject(position_x, position_y)
{
    this->text = text;
}

void anim::AnimatedTextObject::draw_object(const float& current_time)
{
    if (this->start_time > current_time)
    {
        return;
    }

    if (this->stop_time.has_value())
    {
        if (this->stop_time < current_time)
        {
            return;
        }
    }

    this->draw_animation_actions(current_time);

    rl::DrawText(this->text.c_str(), this->position_x, this->position_y, 20, rl::WHITE);
}

void anim::AnimatedTextObject::draw_animation_actions(const float& current_time) // @TODO, consider a better name than trigger
{
    if (this->animation_actions.size() == 0)
    {
        return;
    }

    AnimationAction upcoming_action = this->animation_actions.front();

    if (upcoming_action.execution_time > current_time)
    {
        return;
    }

    switch(upcoming_action.type)
    {
        case AnimationActionType::InstantPositionMovement:

            this->position_x = upcoming_action.position_new_x;
            this->position_y = upcoming_action.position_new_y;
            this->animation_actions.pop();

            break;

        case AnimationActionType::LinearPositionMovement:
        {

            if (upcoming_action.state == AnimationActionState::Inactive)
            {
                this->position_before_an_action_x = this->position_x;
                this->position_before_an_action_y = this->position_y;
                upcoming_action.state = AnimationActionState::Executing;
            }

            float t_start = upcoming_action.execution_time;
            float t_stop = upcoming_action.execution_time + upcoming_action.duration.value(); // @TODO, this can fail, but shouldn't

            float t = (current_time - t_start) / (t_stop - t_start);

            float p1x = this->position_before_an_action_x;
            float p2x = upcoming_action.position_new_x;

            float p1y = this->position_before_an_action_y;
            float p2y = upcoming_action.position_new_y;


            float interpolated_position_x = math::lerp(p1x, p2x, t);
            float interpolated_position_y = math::lerp(p1y, p2y, t);

            this->position_x = interpolated_position_x;
            this->position_y = interpolated_position_y;

            if (t >= 1)
            {
                this->animation_actions.pop();
            }
        }            
            break;

        default:
            break;
    }
}

void anim::AnimatedTextObject::update_position_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position)
{
    if ( this->stop_time.has_value() )
    {
        if (this->start_time + time_to_update_position >= this->stop_time)
        {
            std::cerr << "Attempted to add an animation action that is not possible in the objects display time \n";
            return;
        }
    }

    AnimationAction new_action;
    new_action.state = AnimationActionState::Inactive;
    new_action.type = AnimationActionType::InstantPositionMovement;
    new_action.execution_time = this->start_time + time_to_update_position;
    new_action.duration = std::nullopt;
    new_action.position_new_x = new_position_x;
    new_action.position_new_y = new_position_y;

    this->animation_actions.push(new_action);
}

void anim::AnimatedTextObject::move_position_linearly_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position, const float& duration)
{
    if ( this->stop_time.has_value() )
    {
        if (this->start_time + time_to_update_position >= this->stop_time)
        {
            std::cerr << "Attempted to add an animation action that is not possible in the objects display time \n";
            return;
        }
    }

    AnimationAction new_action;
    new_action.state = AnimationActionState::Inactive;
    new_action.type = AnimationActionType::LinearPositionMovement;
    new_action.execution_time = this->start_time + time_to_update_position;
    new_action.duration = duration;
    new_action.position_new_x = new_position_x;
    new_action.position_new_y = new_position_y;

    this->animation_actions.push(new_action);
}