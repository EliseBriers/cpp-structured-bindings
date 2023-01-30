#include "Float2.h"
#include <cmath>

namespace vector_math {

float Magnitude(const Float2& float2)
{
    return std::hypotf(float2.x, float2.y);
}
} // namespace vector_math
