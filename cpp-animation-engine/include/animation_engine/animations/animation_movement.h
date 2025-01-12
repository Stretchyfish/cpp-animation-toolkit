#pragma once

#include "animation_engine/actions/animation_action.h"
#include "animation_engine/math/lerp.hpp"
#include "animation_engine/math/position.hpp"
#include "animation_engine/animations/animation_response.hpp"

namespace anim
{
    namespace animation
    {
        AnimationResponse linear_position_movement(AnimationAction& action, const float& current_time, const float& current_position_x, const float& current_position_y);
    }
}