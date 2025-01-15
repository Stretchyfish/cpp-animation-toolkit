#pragma once

#include "animation_object.h"
#include <string>
#include <optional>
#include "simple_animation_toolkit/math/lerp.hpp"
#include "simple_animation_toolkit/animations/animation_movement.h"
#include "simple_animation_toolkit/animations/animation_size.h"

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

            std::string text;

        private:

            void draw_animation_actions(const float& current_time);
    };
};
