#include <cpu/cpu.hpp>
#if defined(__APPLE__) || defined(__arm64__)
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <sys/proc.h>
    #include <string>
#endif
CPU::CPU(void)
{}

CPU::~CPU(void)
{}

void CPU::printDetails(void)
{
  std::cout << fmt::format(fg(fmt::rgb(0x00FFAA00)), "--- CPU INFO ---" ) << std::endl;

// macos intel/arm
#if defined(__APPLE__)
  uint64_t curr = 0;
  uint64_t cores = 0;
  int mib[2];
  char modelBuffer[64];
  size_t len = sizeof(curr);
  size_t modelLen = sizeof(modelBuffer);

  mib[0] = CTL_HW;
  mib[1] = HW_NCPU;

  if (sysctlbyname("machdep.cpu.brand_string", &modelBuffer[0], &modelLen, 0, 0) < 0)
    std::cout << fmt::format(fg(fmt::rgb(0xFFFF00)), "--- FAILED TO GET CPU MODEL ---" ) << std::endl;
  else
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Model: ");;
    std::cout << modelBuffer << std::endl;

  if (sysctl(mib, 2, &cores, &len, NULL, 0) < 0)
    std::cout << fmt::format(fg(fmt::rgb(0xFFFF00)), "--- FAILED TO GET CPU CORES ---" ) << std::endl;
  else
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Cores: ");
    std::cout << cores << std::endl;

// arm64 macos m1
#if __arm64__
// empty cpu frequency reading
  return;
#endif // __arm64__

// x86/x64 macos intel
#ifdef __x86_64
  uint64_t min = 0;
  uint64_t max = 0;
  size_t size = sizeof(min);
  if (sysctlbyname("hw.cpufrequency_min", &min, &size, NULL, 0))
    std::cout << fmt::format(fg(fmt::rgb(0xFFFF00)), "--- FAILED TO GET CPU MIN FREQ ---" ) << std::endl;
  else
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Min. Freq: ");
    std::cout << (min / 1000 / 1000) << " MHz " << std::endl;

  if (sysctlbyname("hw.cpufrequency_max", &max, &size, NULL, 0))
    std::cout << fmt::format(fg(fmt::rgb(0xFFFF00)), "--- FAILED TO GET CPU MAX FREQ ---" ) << std::endl;
  else
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Max. Freq: ");
    std::cout << (max/ 1000 / 1000) << " MHz " << std::endl;

  // switch to HW_CPU_FREQ
  mib[1] = HW_CPU_FREQ;

  if (sysctl(mib, 2, &curr, &len, NULL, 0) < 0)
    std::cout << fmt::format(fg(fmt::rgb(0xFFFF00)), "--- FAILED TO GET CPU CURR FREQ ---" ) << std::endl;
  else
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Cur. Freq: ");
    std::cout << (curr / 1000 / 1000) << " MHz " << std::endl;
#endif // __x86_64

#else // != __APPLE__
  auto sockets = hwinfo::getAllSockets();

  for (auto& s : sockets) {
    const auto& cpu = s.CPU();
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Model: ");;
    std::cout << cpu.modelName() << std::endl;

    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Cores: ");
    std::cout << cpu.numPhysicalCores() << std::endl;
    
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Min. Freq: ");
    std::cout << cpu.minClockSpeed_MHz() << " MHz " << std::endl;
 
    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Max. Freq: ");
    std::cout << cpu.maxClockSpeed_MHz() << " MHz " << std::endl;

    std::cout << std::left << std::setw(20) << fmt::format(fg(fmt::rgb(0xFFFF00)), "Cur. Freq: ");
    std::cout << cpu.currentClockSpeed_MHz() << " MHz " << std::endl;
  }
#endif // __APPLE__
}

// returns frequncy in MHz
uint64_t CPU::getCurrFrequency(void)
{
  uint64_t freqMhz = 0;

// specific code for macos intel/arm
#if defined(__APPLE__)
#if __arm64__
  return -1;
#endif 

    int mib[2];
    size_t len = sizeof(freqMhz);
    mib[0] = CTL_HW;
    mib[1] = HW_CPU_FREQ;

    if (sysctl(mib, 2, &freqMhz, &len, NULL, 0) < 0)
      return -1;
    else
      return (freqMhz / 1000 / 1000);
#else // != __APPLE__
  auto sockets = hwinfo::getAllSockets();
  for (auto& s : sockets) {
    const auto& cpu = s.CPU();
    freqMhz = cpu.currentClockSpeed_MHz();
    break;
  }
#endif // __APPLE__
  return freqMhz;
}
