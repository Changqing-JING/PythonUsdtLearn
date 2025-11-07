#include <chrono>
#include <cstdint>
#include <iostream>
#include <sys/prctl.h>
#include <sys/sdt.h>
#include <thread>
#include <unistd.h>

int main() {
  // Set process name similar to Python setproctitle
  prctl(PR_SET_NAME, "cppapp", 0, 0, 0);

  std::cout << "C++ USDT Example" << std::endl;
  std::cout << "PID: " << getpid() << std::endl;
  std::cout << "Process name: cppapp" << std::endl;

  while (true) {
    std::cout << "Firing probe..." << std::endl;
    uint64_t value = 42;
    int32_t count = 1;

    // Fire probe with C++ provider name
    DTRACE_PROBE2(cppapp, firstProbe, value, count);

    std::cout << "Probe fired!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}