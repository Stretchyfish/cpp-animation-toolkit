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

