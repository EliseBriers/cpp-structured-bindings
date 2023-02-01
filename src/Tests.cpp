#include "Float2.h"
#include <catch_amalgamated.hpp>
#include <map>
#include <strings.h>

namespace test_structured_bindings {
TEST_CASE("Structured binding on array", "[array]")
{
    auto coordinates = std::array<int, 3> { 15, 17, -3 };

    const auto& [coordX, coordY, coordZ] = coordinates;

    REQUIRE(coordY == 17);

    coordinates[1] = 60;

    REQUIRE(coordY == 60);
}
}

namespace test_structured_bindings_basics {
TEST_CASE("Binding pair using variable assignment.", "[pair]")
{
    const auto index = std::pair { 3, 5 };

    const auto row = index.first;
    const auto column = index.second;

    // ...

    // I know these unit tests are dumb, but they're here for the sake of completion.
    REQUIRE(row == 3);
    REQUIRE(column == 5);
}

TEST_CASE("Binding pair using structured bindings.", "[pair]")
{
    const auto index = std::pair { 3, 5 };

    const auto& [row, column] = index;

    // ...

    REQUIRE(row == 3);
    REQUIRE(column == 5);
}

// Uncomment the following line to enable the invalid test.
// #define STRUCTURED_BINDINGS_ILLEGAL_EXAMPLE
#ifdef STRUCTURED_BINDINGS_ILLEGAL_EXAMPLE
TEST_CASE("Binding pair using structured bindings in the wrong way", "[pair]")
{
    const auto index = std::pair { 3, 5 };

    const int & [ row, column ] = index;

    // ...

    REQUIRE(row == 3);
    REQUIRE(column == 5);
}
#endif // STRUCTURED_BINDINGS_ILLEGAL_EXAMPLE
}

namespace test_vector_math_universal {
using namespace vector;
using namespace vector_math_universal;
using Catch::Approx;

TEST_CASE("Magnitude returns the magnitude of a Float2", "[magnitude]")
{
    const auto float2 = Float2 { 3.F, -4.F };
    const auto expectedMagnitude = Approx { 5.F };

    REQUIRE(Magnitude(float2) == expectedMagnitude);
}

TEST_CASE("Calculating the magnitude of a vector of length 0", "[magnitude]")
{
    const auto float2 = Float2 { 0.F, 0.F };
    const auto expectedMagnitude = Approx { 0.F };

    REQUIRE(Magnitude(float2) == expectedMagnitude);
}

namespace test_vector_math_part1 {
    using namespace vector_math_part1;
    using Catch::Approx;

    TEST_CASE("Normalized vector returns pair of normal and magnitude. // Part1", "[normalized]")
    {
        const auto expectedMagnitude = Approx { 5.F };
        const auto expectedX = Approx { 3.F / 5.F };
        const auto expectedY = Approx { -4.F / 5.F };

        const auto float2 = Float2 { 3.F, -4.F };

        const auto normalizedResult = Normalized(float2);

        const auto normal = normalizedResult.first;
        const auto magnitude = normalizedResult.second;

        // ...

        REQUIRE(magnitude == expectedMagnitude);
        REQUIRE(normal.x == expectedX);
        REQUIRE(normal.y == expectedY);
    }

    TEST_CASE("Normalized vector returns pair of normal and magnitude, extracted using structured bindings. // Part1", "[normalized]")
    {
        const auto expectedMagnitude = Approx { 5.F };
        const auto expectedX = Approx { 3.F / 5.F };
        const auto expectedY = Approx { -4.F / 5.F };

        const auto float2 = Float2 { 3.F, -4.F };

        const auto [normal, magnitude] = Normalized(float2);

        // ...

        REQUIRE(magnitude == expectedMagnitude);
        REQUIRE(normal.x == expectedX);
        REQUIRE(normal.y == expectedY);
    }
}

namespace test_vector_math_part2 {
    using namespace vector_math_part2;
    using Catch::Approx;

    TEST_CASE("Normalized vector returns pair of normal and magnitude. // part2", "[normalized]")
    {
        const auto expectedMagnitude = Approx { 5.F };
        const auto expectedX = Approx { 3.F / 5.F };
        const auto expectedY = Approx { -4.F / 5.F };

        const auto float2 = Float2 { 3.F, -4.F };

        const auto normalizedResult = Normalized(float2);

        const auto normal = normalizedResult.normal;
        const auto magnitude = normalizedResult.magnitude;

        // ...

        REQUIRE(magnitude == expectedMagnitude);
        REQUIRE(normal.x == expectedX);
        REQUIRE(normal.y == expectedY);
    }

    TEST_CASE("Normalized vector returns pair of normal and magnitude, extracted using structured bindings. // Part2", "[normalized]")
    {
        const auto expectedMagnitude = Approx { 5.F };
        const auto expectedX = Approx { 3.F / 5.F };
        const auto expectedY = Approx { -4.F / 5.F };

        const auto float2 = Float2 { 3.F, -4.F };

        const auto [normal, magnitude] = Normalized(float2);

        // ...

        REQUIRE(magnitude == expectedMagnitude);
        REQUIRE(normal.x == expectedX);
        REQUIRE(normal.y == expectedY);
    }
}

namespace test_vector_math_part3 {
    using namespace vector_math_part3;
    using Catch::Approx;

    TEST_CASE("Normalized vector returns pair of normal and magnitude. // part3", "[normalized]")
    {
        const auto expectedMagnitude = Approx { 5.F };
        const auto expectedX = Approx { 3.F / 5.F };
        const auto expectedY = Approx { -4.F / 5.F };

        const auto float2 = Float2 { 3.F, -4.F };

        const auto normalizedResult = Normalized(float2);

        const auto normal = normalizedResult.normal;
        const auto magnitude = normalizedResult.magnitude;

        // ...

        REQUIRE(magnitude == expectedMagnitude);
        REQUIRE(normal.x == expectedX);
        REQUIRE(normal.y == expectedY);
    }

    TEST_CASE("Normalized vector returns pair of normal and magnitude, extracted using structured bindings. // Part3", "[normalized]")
    {
        const auto expectedMagnitude = Approx { 5.F };
        const auto expectedX = Approx { 3.F / 5.F };
        const auto expectedY = Approx { -4.F / 5.F };

        const auto float2 = Float2 { 3.F, -4.F };

        const auto [normal, magnitude, sqrMagnitude] = Normalized(float2);

        // ...

        REQUIRE(magnitude == expectedMagnitude);
        REQUIRE(normal.x == expectedX);
        REQUIRE(normal.y == expectedY);
    }
}

namespace test_loop_trough_map {
    using city_map_t = std::map<std::string, size_t>;

    TEST_CASE("Loop through map the normal way.", "[map]")
    {
        auto citiesAndInhabitants = city_map_t {};

        citiesAndInhabitants["Tokyo"] = 37'468'000U;
        citiesAndInhabitants["Beijing"] = 19'618'000U;
        citiesAndInhabitants["New York"] = 18'819'000U;
        citiesAndInhabitants["Los Angeles"] = 12'458'000U;

        for (const auto& iter : citiesAndInhabitants) {
            const auto name = iter.first;
            const auto population = iter.second;

            // Some code that uses name and population...
        }
    }

    TEST_CASE("Loop through map using structured bindings.", "[map]")
    {
        auto citiesAndInhabitants = city_map_t {};

        citiesAndInhabitants["Tokyo"] = 37'468'000U;
        citiesAndInhabitants["Beijing"] = 19'618'000U;
        citiesAndInhabitants["New York"] = 18'819'000U;
        citiesAndInhabitants["Los Angeles"] = 12'458'000U;

        for (const auto& [name, population] : citiesAndInhabitants) {
            // Some code that uses name and population...
        }
    }
}
}
