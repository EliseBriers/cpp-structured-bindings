#include "catch_amalgamated.hpp"

TEST_CASE("Structured binding on array", "[array]")
{
    std::array<int, 3> coordinates { 15, 17, -3 };

    const auto& [coordX, coordY, coordZ] = coordinates;

    REQUIRE(coordY == 17);

    coordinates[1] = 60;

    REQUIRE(coordY == 60);
}
