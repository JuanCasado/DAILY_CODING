#include "JOB_SCHEDULER.hpp"

#include <iostream>
#include <string>

void print_num(std::string name) {
  std::cout << name << std::endl; 
}

int main(int argc, char const *argv[]) {
  Scheduler scheduler;
  scheduler.schedule(1000, &print_num, "FUNCTION 1");
  scheduler.schedule(500, &print_num, "FUNCTION 2");
  scheduler.schedule(200, &print_num, "FUNCTION 3");
  scheduler.schedule(400, &print_num, "FUNCTION 4");
  scheduler.schedule(200, &print_num, "FUNCTION 5");
  std::this_thread::sleep_for(std::chrono::milliseconds(10000));
  return 0;
}
#include "DICTIONARY_QUERRY.hpp"

int main(int argc, char const *argv[]) {
	return 0;
}
