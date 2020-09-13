#ifndef ALL_TESTS
#define CATCH_CONFIG_MAIN
#endif
#include <catch2/catch.hpp>

#define protected public
#include "../src/common/growingmenuitem.hpp"
#undef protected

TEST_CASE("Initailising item", "[growing menu item]")
{
    GrowingMenuItem item(0, false);

    item.init("test String", sf::Font());
    REQUIRE(item.m_baseSize != 0);
}
