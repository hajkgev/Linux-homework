#include "scheduler_lib.h"

void parallel_scheduler::error_check(int out) {
  if (out != 0) {
    std::cerr << "ERROR : " << out << std::endl;
    exit(out);
  }
}


void *parallel_scheduler::consumer(void *arg) {
  
  auto *data = (parallel_scheduler *) arg;

  
  std::function<void(void *)> func;

  
  void *func_arg;
