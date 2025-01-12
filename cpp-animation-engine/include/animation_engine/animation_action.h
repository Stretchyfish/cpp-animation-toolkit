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

    struct AnimationAction
    {
        AnimationActionType type;
        float execution_time;
        std::optional<float> duration;
        float position_new_x;
        float position_new_y;
    };
};