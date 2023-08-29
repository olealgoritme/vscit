add_executable(vscit app.cpp)
target_compile_features(vscit PRIVATE cxx_std_17)
target_link_libraries(vscit PRIVATE cpu)
