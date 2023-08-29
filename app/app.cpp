#include <iostream>
#include <iomanip>
#include <string>
#include <cpu/cpu.hpp>

int main (int argc, char *argv[])
{
  // print cpu information
  CPU cpu = CPU();
  cpu.printDetails();

  return 0;
}
