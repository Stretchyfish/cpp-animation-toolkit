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

            std::string text;

        private:

            void draw_animation_actions(const float& current_time);
    };
};
