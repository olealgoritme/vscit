# libcpu header list
set(HEADER_LIST "${vscit_SOURCE_DIR}/include/cpu/cpu.hpp")

# add library with source and header files
add_library(cpu SHARED cpu.cpp ${HEADER_LIST})

# include include directory
target_include_directories(cpu PUBLIC ../include)

# link with library dependencies
target_link_libraries(cpu PUBLIC fmt::fmt)

# add hwinfo lib (for all except darwin/macosx based arch)
if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(cpu PUBLIC hwinfo::HWinfo)
endif()

# library min C++ version
target_compile_features(cpu PUBLIC cxx_std_17)
