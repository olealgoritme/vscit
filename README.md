[![Linux (gcc/clang)](https://github.com/olealgoritme/vscit/actions/workflows/cmake-linux.yml/badge.svg)](https://github.com/olealgoritme/vscit/actions/workflows/cmake-linux.yml)

[![MacOS ARM](https://github.com/olealgoritme/vscit/actions/workflows/cmake-macos-arm.yml/badge.svg)](https://github.com/olealgoritme/vscit/actions/workflows/cmake-macos-arm.yml)

[![MacOS x64](https://github.com/olealgoritme/vscit/actions/workflows/cmake-macos-x64.yml/badge.svg)](https://github.com/olealgoritme/vscit/actions/workflows/cmake-macos-x64.yml)

[![Windows (MSVC)](https://github.com/olealgoritme/vscit/actions/workflows/cmake-windows.yml/badge.svg)](https://github.com/olealgoritme/vscit/actions/workflows/cmake-windows.yml)

### VSCIT - Very Small CPU Information Tool 
- Displays CPU info:
  - CPU model name
  - Physical CPU core count
  - Minimum CPU core frequency
  - Maximum CPU core frequency
  - Current CPU core frequency

- OS compatibility:
  - Windows
  - Linux
  - MacOS (Intel + arm64 (limited))

- GitHub Actions CI:
  - CMake build system
  - OS support:
    - Windows
    - Linux
    - MacOS
  - Compilers:
    - gcc
    - clang
    - cl

- Third party libraries used:
  - hwinfo (git submodule)
  - fmt (CMake fetched)
  - catch2 (CMake fetched)


##### Linux/MacOS Install
```bash
git clone https://github.com/olealgoritme/vscit.git
cd vscit
make
```

##### Windows Install
```bash
git clone https://github.com/olealgoritme/vscit.git
cd vscit
git submodule update --init --recursive
cmake -S . -B build
cmake --build build
```
