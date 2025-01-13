#pragma once

#include "animation_object.h"
#include <string>
#include <optional>
#include "animation_engine/math/lerp.hpp"
#include "animation_engine/animations/animation_movement.h"
#include "animation_engine/animations/animation_size.h"

namespace rl
{
    #include <raylib.h>
}

namespace anim
{
    class AnimatedTextObject : public AnimationObject
    {
        public:
            AnimatedTextObject();
            AnimatedTextObject(std::string text, int position_x, int position_y);

            void draw_object(const float& current_time);
            void add_position_move_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position);
            void add_position_move_linearly_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position, const float& duration);
            void add_size_change_after(const float& new_size, const float& time_to_update_position);
            void add_size_change_after(const float& new_size, const float& time_to_update_position, const float& duration);

            std::string text;

        private:

            void draw_animation_actions(const float& current_time);
    };
};
