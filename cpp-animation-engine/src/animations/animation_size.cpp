#include "animation_engine/animations/animation_size.h"

namespace anim
{
    namespace animation
    {
        AnimationResponse linear_size_change(AnimationAction& action, const float& current_time, const float& current_size)
        {
            if (action.state == AnimationActionState::Inactive)
            {
                action.size_at_start_of_action = current_size;
                action.state = AnimationActionState::Executing;
            }

            if ( !action.duration.has_value() )
            {
                std::cout << "Warning, linear size change has not been setup correctly, missing duration \n";

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

            float s1 = action.size_at_start_of_action;
            float s2 = action.size_new;

            float interpolated_size = math::lerp(s1, s2, t);

            AnimationResponse response;
            response.size = interpolated_size;
            response.state = AnimationState::OnGoing;
            return response;
        }
    }
}