#ifndef ALL_TESTS
#define CATCH_CONFIG_MAIN
#endif
#include <catch2/catch.hpp>

TEST_CASE("Level Tests", "[app]")
{
    SECTION("Hello World") {
        REQUIRE(true);
    }
}
