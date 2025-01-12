#pragma once

#include <iostream>
#include <optional>

namespace anim
{
    enum AnimationActionType
    {
        InstantPositionMovement,
        LinearPositionMovement
    };

    enum AnimationActionState
    {
        Inactive,
        Executing
    };

    struct AnimationAction
    {
        AnimationActionState state;
        AnimationActionType type;
        float execution_time;
        std::optional<float> duration;
        float position_new_x;
        float position_new_y;
        float position_x_at_start_of_action;
        float position_y_at_start_of_action;
    };
};