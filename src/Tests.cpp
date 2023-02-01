#include "Float2.h"
#include <catch_amalgamated.hpp>

namespace test_structured_bindings {

TEST_CASE("Structured binding on array", "[array]")
{
    std::array<int, 3> coordinates { 15, 17, -3 };

    const auto& [coordX, coordY, coordZ] = coordinates;

    REQUIRE(coordY == 17);

    coordinates[1] = 60;

    REQUIRE(coordY == 60);
}

}

namespace test_vector {
using namespace vector;

TEST_CASE("Magnitude returns the magnitude of a Float2", "[magnitude]")
{
    using namespace vector_math_part1;

    const Float2 float2 { 3.F, -4.F };
    const float expectedMagnitude = 5.F;

    REQUIRE(Magnitude(float2) == Catch::Approx(expectedMagnitude));
}

TEST_CASE("Calculating the magnitude of a vector of length 0", "[magnitude]")
{
    using namespace vector_math_part1;

    const Float2 float2 { 0.F, 0.F };
    const float expectedMagnitude = 0.F;

    REQUIRE(Magnitude(float2) == Catch::Approx(expectedMagnitude));
}

}
