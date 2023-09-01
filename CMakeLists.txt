# set cmake version
cmake_minimum_required(VERSION 3.6)

# project info
project(
  vscit
  VERSION 0.1
  DESCRIPTION "Cross platform cpu information tool"
  LANGUAGES CXX
)

# set cmake options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall --std=c++17 -O3 -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# windows specific options
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

# fetch fmt lib
include(FetchContent) 
FetchContent_Declare(
  libfmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.1.0)
FetchContent_MakeAvailable(libfmt)

# add hwinfo lib (for all except darwin/macosx based arch)
if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  add_subdirectory(lib/hwinfo)
  include_directories(lib/hwinfo/include)
endif()

# add library source directory (libcpu)
add_subdirectory(src)

# add app source directory (vscit)
add_subdirectory(app)

# tests
include(CTest)
enable_testing()
add_subdirectory(tests)
