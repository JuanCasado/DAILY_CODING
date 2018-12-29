#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <cstdlib>

struct SumSearchData {
    int first_to_match = 0;
    int second_to_match = 0;
    bool matched = false;
};

void printVector(const std::vector<int> &p_vector, const std::string &separator);
void sumSeach (const int &target, const std::vector<int> &p_vector, SumSearchData &ssd);