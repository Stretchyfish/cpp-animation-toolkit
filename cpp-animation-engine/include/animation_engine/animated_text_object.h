#pragma once

#include "animation_object.h"
#include <string>
#include <optional>
#include "math/lerp.hpp"

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
            void update_position_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position);
            void move_position_linearly_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position, const float& duration);

            std::string text; // @TODO, should this be a private variable, accessed with a public function?

        private:

            void draw_animation_actions(const float& current_time);
    };
};
