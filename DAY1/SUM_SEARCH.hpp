#ifndef SUM_SEARCH_HPP
#define SUM_SEARCH_HPP

#include <vector>
#include <string>

struct SumSearchData {
    int first_to_match = 0;
    int second_to_match = 0;
    bool matched = false;
};

void sumSeach (const int &target, const std::vector<int> &p_vector, SumSearchData &ssd);

#endif
