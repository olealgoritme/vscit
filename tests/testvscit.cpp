#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cpu/cpu.hpp>

TEST_CASE( "Quick test", "[test]" ) {
    REQUIRE( 1.0 == 1.0 );
}

TEST_CASE( "Can Read CPU frequency", "[cpu]" ) {
    CPU cpu = CPU();
    uint64_t freq = cpu.getCurrFrequency();
    REQUIRE( freq != 0 );
}
