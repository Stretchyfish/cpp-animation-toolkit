#pragma once

namespace anim
{
    namespace math
    {
        inline float lerp(float a, float b, float t)
        {
            return a + t * (b - a);
        }
    }
}