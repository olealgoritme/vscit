#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cpu/cpu.hpp>

TEST_CASE( "Quick test", "[test]" ) {
    REQUIRE( 1.0 == 1.0 );
}

TEST_CASE( "Can Read CPU frequency", "[cpu]" ) {
#if defined(__APPLE__)
#if __arm64__
  // can't read cpu frequency
#else
    CPU cpu = CPU();
    uint64_t freq = cpu.getCurrFrequency();
    REQUIRE( freq != 0 );

#endif // __arm64__
#endif // __APPLE__
}
