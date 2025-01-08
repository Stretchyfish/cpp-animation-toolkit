#include "animation_engine/animation_object.h"

anim::AnimationObject::AnimationObject()
{
    this->position_x = 0;
    this->position_y = 0;
    this->position_z = 0;
}

anim::AnimationObject::AnimationObject(int position_x, int position_y)
{
    this->position_x = position_x;
    this->position_y = position_y;
    this->position_z = 0;
}