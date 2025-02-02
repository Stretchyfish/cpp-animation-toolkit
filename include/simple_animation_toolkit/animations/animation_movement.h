#pragma once

#include "simple_animation_toolkit/actions/animation_action.h"
#include "simple_animation_toolkit/math/lerp.hpp"
#include "simple_animation_toolkit/math/position.hpp"
#include "simple_animation_toolkit/animations/animation_response.hpp"

namespace sat
{
    namespace animation
    {
        AnimationResponse linear_position_movement(AnimationAction& action, const float& current_time, const float& current_position_x, const float& current_position_y);
    }
}