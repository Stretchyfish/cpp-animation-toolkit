#include "simple_animation_toolkit/objects/animated_text_object.h"

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

    rl::Font default_font = rl::GetFontDefault();
    rl::Vector2 text_size = rl::MeasureTextEx(default_font, this->text.c_str(), this->size, 0);

    //rl::Vector2 text_size = rl::MeasureText(this->text.c_str(), this->size);

    rl::DrawText(this->text.c_str(), this->position_x - text_size.x / 2, this->position_y - text_size.y / 2, this->size, rl::WHITE);
}

void anim::AnimatedTextObject::draw_animation_actions(const float& current_time) // @TODO, consider a better name than trigger
{
    if (this->animation_actions.size() == 0)
    {
        return;
    }

    AnimationAction& upcoming_action = this->animation_actions.front();

    if (upcoming_action.execution_time > current_time)
    {
        return;
    }
    
    animation::AnimationResponse reponse;
    switch(upcoming_action.type)
    {
        case AnimationActionType::InstantPositionMovement:

            this->position_x = upcoming_action.position_new_x;
            this->position_y = upcoming_action.position_new_y;
            this->animation_actions.pop();

            return;

        case AnimationActionType::LinearPositionMovement:
            reponse = animation::linear_position_movement(upcoming_action, current_time, this->position_x, this->position_y);
            break;

        case AnimationActionType::SizeChange:

            this->size = upcoming_action.size_new;
            this->animation_actions.pop();
            //reponse = animation::size_change(upcoming_action, current_time, 5);
            return;

        case AnimationActionType::LinearSizeChange:
            reponse = animation::linear_size_change(upcoming_action, current_time, this->size);
            break;

        default:
            std::cerr << "An action was executed that isn't defined, removing it from the queue \n";
            this->animation_actions.pop();
            return;
    }


    switch(reponse.state)
    {
        case animation::AnimationState::Invalid:
        {
            std::cerr << "An action was played that is not setup correctly, removing it from the queue \n";
            this->animation_actions.pop();
            return;
        }

        case animation::AnimationState::OnGoing:

            if (upcoming_action.type == AnimationActionType::LinearPositionMovement)
            {
                this->position_x = reponse.position_x;
                this->position_y = reponse.position_y;
                return;
            }

            if (upcoming_action.type == AnimationActionType::LinearSizeChange)
            {
                this->size = reponse.size;
                return;
            }

        case animation::AnimationState::Finished:

            if (upcoming_action.type == AnimationActionType::LinearPositionMovement)
            {
                this->position_x = reponse.position_x;
                this->position_y = reponse.position_y;
                this->animation_actions.pop();
                return;
            }

            if (upcoming_action.type == AnimationActionType::LinearSizeChange)
            {
                this->size = reponse.size;
                this->animation_actions.pop();
                return;
            }

        default:
            break;
    }
}