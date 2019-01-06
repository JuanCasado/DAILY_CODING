#include "MAXIMUM_SUM_EXCLUDING_ADJACENT.hpp"

int maximumSumExcludingAdjacent(const std::vector<int> &p_vector) {
  int previous_included_count = 0;
  int previous_excluded_count = 0;
  for (auto &elem : p_vector){
    int current_excluded_count = std::max(previous_included_count, previous_excluded_count);
    previous_included_count = previous_excluded_count + elem;
    previous_excluded_count = current_excluded_count;
  }
  return std::max(previous_excluded_count,previous_included_count);;
}