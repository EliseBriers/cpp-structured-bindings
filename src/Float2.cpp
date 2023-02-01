#include "Float2.h"
#include <cmath>

namespace vector::vector_math_universal {
float Magnitude(const Float2& float2)
{
    return std::hypotf(float2.x, float2.y);
}
}

namespace vector::vector_math_part1 {
std::pair<Float2, float> Normalized(Float2 float2)
{
    float magnitude { Magnitude(float2) };
    float2.x /= magnitude;
    float2.y /= magnitude;

    return { float2, magnitude };
}
} // namespace vector_math_part1

namespace vector::vector_math_part2 {
NormalizedResult Normalized(Float2 float2)
{
    float magnitude { Magnitude(float2) };
    float2.x /= magnitude;
    float2.y /= magnitude;

    return { float2, magnitude };
}
} // namespace vector_math_part2
