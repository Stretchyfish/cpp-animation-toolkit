#include "animation_engine/objects/animation_object.h"

anim::AnimationObject::AnimationObject()
{
    this->position_x = 0;
    this->position_y = 0;
    this->position_z = 0;
    this->start_time = 0;
    this->stop_time = std::nullopt;
}

anim::AnimationObject::AnimationObject(const int& position_x, const int& position_y)
{
    this->position_x = position_x;
    this->position_y = position_y;
    this->position_z = 0;
    this->start_time = 0;
    this->stop_time = std::nullopt;
    this->size = 20;
}

void anim::AnimationObject::set_start_time(const float& new_start_time)
{
    this->start_time = new_start_time;
}

void anim::AnimationObject::set_stop_time(const float& new_stop_time)
{
    this->stop_time = new_stop_time;
}

void anim::AnimationObject::draw_object(const float& current_time)
{
    std::cerr << "Drawing was not defined for the object that is being drawn \n";
}

void anim::AnimationObject::draw_animation_actions(const float& current_time)
{
    std::cerr << "Triger animation action was not defined for the object it is being called in \n";
}

void anim::AnimationObject::add_position_move_instant_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position)
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

void anim::AnimationObject::add_position_move_linear_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position, const float& duration)
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

void anim::AnimationObject::add_size_change_instant_after(const float& new_size, const float& time_to_update_position)
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
    new_action.type = AnimationActionType::SizeChange;
    new_action.execution_time = this->start_time + time_to_update_position;
    new_action.duration = std::nullopt;
    new_action.size_new = new_size;

    this->animation_actions.push(new_action);
}

void anim::AnimationObject::add_size_change_linear_after(const float& new_size, const float& time_to_update_position, const float& duration)
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
    new_action.type = AnimationActionType::LinearSizeChange;
    new_action.execution_time = this->start_time + time_to_update_position;
    new_action.duration = duration;
    new_action.size_new = new_size;

    this->animation_actions.push(new_action);
}