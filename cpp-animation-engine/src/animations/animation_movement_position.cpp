#pragma once

#include "animation_engine/actions/animation_action.h"
#include "animation_engine/math/lerp.hpp"
#include "animation_engine/math/position.hpp"
#include "animation_engine/animations/animation_response.hpp"

namespace anim
{
    namespace animation
    {
        AnimationResponse linear_position_movement(AnimationAction& action, const float& current_time, const float& current_position_x, const float& current_position_y)
        {
            if (action.state == AnimationActionState::Inactive)
            {
                action.position_x_at_start_of_action = current_position_x;
                action.position_y_at_start_of_action = current_position_y;
                action.state = AnimationActionState::Executing;
            }

            if ( !action.duration.has_value() )
            {
                std::cout << "Warning, linear position movement has not been setup correctly, missing duration \n";

                AnimationResponse reposne;
                reposne.state = AnimationState::Invalid;
                return reposne;
            }

            float t_start = action.execution_time;
            float t_stop = action.execution_time + action.duration.value();
            
            if (t_start >= t_stop)
            {
                AnimationResponse reposne;
                reposne.state = AnimationState::Finished;
                return reposne;
            }

            float t = (current_time - t_start) / (t_stop - t_start);
            t = std::max(0.0f, std::min(1.0f, t));

            float p1x = action.position_x_at_start_of_action;
            float p2x = action.position_new_x;

            float p1y = action.position_y_at_start_of_action;
            float p2y = action.position_new_y;

            float interpolated_position_x = math::lerp(p1x, p2x, t);
            float interpolated_position_y = math::lerp(p1y, p2y, t);

            AnimationResponse response;
            response.position_x = interpolated_position_x;
            response.position_y = interpolated_position_y;
            response.state = AnimationState::OnGoing;
            return response;
        }
    }
} // namespace anim