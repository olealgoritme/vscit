#ifndef __CPU_H__
#define __CPU_H__
#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#if defined(__APPLE__) || defined(__arm64__)
#else 
#include <hwinfo/cpu.h>
#endif
#include <fmt/color.h>

class CPU {
    public:
      CPU(void);
      ~CPU(void);
      void printDetails(void);
      uint64_t getCurrFrequency(void);
};



#endif //  __CPU_H__
