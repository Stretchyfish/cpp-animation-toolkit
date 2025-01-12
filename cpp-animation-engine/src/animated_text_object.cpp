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

            

            
            break;

        default:
            break;
    }


    std::cout << "Action should be triggered now" << std::endl;

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
    new_action.type = AnimationActionType::LinearPositionMovement;
    new_action.execution_time = this->start_time + time_to_update_position;
    new_action.duration = duration;
    new_action.position_new_x = new_position_x;
    new_action.position_new_y = new_position_y;

    this->animation_actions.push(new_action);
}