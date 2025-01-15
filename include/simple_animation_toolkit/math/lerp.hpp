#pragma once

namespace sat
{
    namespace math
    {
        inline float lerp(float a, float b, float t)
        {
            t = std::max(0.0f, std::min(1.0f, t));
            return a + t * (b - a);
        }
    } // namespace math
} // namespace anim