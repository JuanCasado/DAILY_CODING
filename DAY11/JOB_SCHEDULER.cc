#include "JOB_SCHEDULER.hpp"

void Scheduler::schedule(int delay, void (*function)(std::string), std::string args) {
  saved_functions_mutex.lock();
  saved_functions.emplace(StoredFuntion{delay, function, args});
  hilo = std::thread(&Scheduler::callFirstFunction, this);
  hilo.detach();
  saved_functions_mutex.unlock();
}
long Scheduler::getTime() {
  long time = -1;
  saved_functions_mutex.lock();
  if (!saved_functions.empty()) time = saved_functions.top().getTime();
  saved_functions_mutex.unlock();
  return time;
}
bool Scheduler::isEmpty() {
  bool state = true;
  saved_functions_mutex.lock();
  state = saved_functions.empty();
  saved_functions_mutex.unlock();
  return state;
}
void Scheduler::callFunction() {
  saved_functions_mutex.lock();
  saved_functions.top().callFunction();
  saved_functions.pop();
  saved_functions_mutex.unlock();
}
void Scheduler::callFirstFunction() {
  long time = 0;
  if ((time = getTime()) > 0)
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
  callFunction();
}