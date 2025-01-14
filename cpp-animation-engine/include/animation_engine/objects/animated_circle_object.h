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
