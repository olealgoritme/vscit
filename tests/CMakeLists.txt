# fetch catch2 testing lib
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)

# executable test file
add_executable(testvscit testvscit.cpp)

# link executable testvscit with catch2 and libcpu
target_link_libraries(testvscit PRIVATE Catch2::Catch2 cpu)

# register named test with command
add_test(NAME simpletest COMMAND testvscit)
