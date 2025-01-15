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
    class AnimatedCircleObject : public AnimationObject
    {
        public:
            AnimatedCircleObject();
            AnimatedCircleObject(float size, float position_x, float position_y);

            void draw_object(const float& current_time);

        private:
            void draw_animation_actions(const float& current_time);


    };
};
