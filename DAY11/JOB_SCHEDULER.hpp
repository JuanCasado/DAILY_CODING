#ifndef JOB_SCHEDULER_HPP
#define JOB_SCHEDULER_HPP

#include <chrono>
#include <condition_variable>
#include <queue>
#include <sstream>
#include <thread>
#include <vector>

/* GENERAL APROACH
template <typename funtion_type, typename... args_types>
void schedule(int delay, funtion_type function, args_types... args) {

  function(args...);
}
*/

class Scheduler {
 public:
  void schedule(int delay, void (*function)(std::string), std::string args);

 private:
  class StoredFuntion {
   public:
    StoredFuntion(int delay, void (*function)(std::string), std::string args)
        : delay{delay},
          function{function},
          args{args},
          timestamp{std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::time_point_cast<std::chrono::milliseconds>(
                            std::chrono::high_resolution_clock::now())
                            .time_since_epoch())
                        .count()} {}
    int getTime() const {
      return (timestamp + delay) -
             std::chrono::duration_cast<std::chrono::milliseconds>(
                 std::chrono::time_point_cast<std::chrono::milliseconds>(
                     std::chrono::high_resolution_clock::now())
                     .time_since_epoch())
                 .count();
    }
    void callFunction() const { function(args); }
    std::string print() const {
      std::stringstream ss;
      ss << "Args: " << args;
      ss << " Delay: " << delay;
      ss << " Time stamp: " << timestamp;
      return ss.str();
    }
    friend bool operator<(const StoredFuntion &f1, const StoredFuntion &f2) {
      return f1.getTime() > f2.getTime();
    }

   private:
    long delay;
    void (*function)(std::string);
    std::string args;
    long timestamp;
  };
  std::thread hilo;
  std::priority_queue<StoredFuntion> saved_functions;
  std::mutex saved_functions_mutex;
  long getTime();
  bool isEmpty();
  void callFunction();
  void callFirstFunction();
};

#endif
