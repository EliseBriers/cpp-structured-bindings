#ifndef FLOAT2_H
#define FLOAT2_H

#include <utility>
namespace vector {
struct Float2 {
    float x;
    float y;
};

namespace vector_math_universal {
    float Magnitude(const Float2& float2);
    float SqrMagnitude(const Float2& float2);
}

namespace vector_math_part1 {
    using namespace vector_math_universal;

    std::pair<Float2, float> Normalized(Float2 float2);
} // namespace vector_math_part1

namespace vector_math_part2 {
    using namespace vector_math_universal;

    struct NormalizedResult {
        Float2 normal;
        float magnitude;
    };

    NormalizedResult Normalized(Float2 float2);
} // namespace vector_math_part2

namespace vector_math_part3 {
    using namespace vector_math_universal;

    struct NormalizedResult {
        Float2 normal;
        float magnitude;
        float sqrMagnitude;
    };

    NormalizedResult Normalized(Float2 float2);
} // namespace vector_math_part3
} // namespace vector

#endif // !FLOAT2_H
