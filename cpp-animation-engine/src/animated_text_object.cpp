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



    rl::DrawText(this->text.c_str(), this->position_x, this->position_y, 20, rl::WHITE);
}

void anim::AnimatedTextObject::update_position_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position)
{
    
}

