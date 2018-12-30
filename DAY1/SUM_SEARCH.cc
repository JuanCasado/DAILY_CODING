#include "SUM_SEARCH.hpp"

void sumSeach(const int &target, const std::vector<int> &p_vector, SumSearchData &ssd){
    int min_index = 0;
    int max_index = p_vector.size() -1;
    int sum = 0;
    bool control = true;
    while (control){
        sum = p_vector[min_index] + p_vector[max_index];
        if (sum == target){
            ssd.matched = true;
            ssd.first_to_match = min_index;
            ssd.second_to_match = max_index;
            control = false;
        } else {
            if (sum < target){
                ++ min_index;
                if (min_index >= max_index){
                    ssd.matched = false;
                    control = false;
                }
            }else {
                -- max_index;
                if (min_index <= max_index){
                    ssd.matched = false;
                    control = false;
                }
            }
        }
    }
}