#include <iostream>
#include <sstream>
#include <cstdlib>

#include "SUM_SEARCH.hpp"

std::string printVector(const std::vector<int> &p_vector, const std::string &separator);
void initData(std::vector<int> &p_vector, int &p_target, const int &argc, const char *argv[]);

int main(int argc, char const *argv[]){
    std::vector<int> num_list;
    int target;
    initData(num_list, target, argc, argv);
    std::cout << "Target: " << target << std::endl;
    std::cout << "Initial data: [" << printVector(num_list, ", ") << "]" << std::endl;

    std::sort(num_list.begin(), num_list.end());
    std::cout << "Sorted data: [" << printVector(num_list, ", ") << "]" << std::endl;

    SumSearchData ssd;
    sumSeach(target, num_list, ssd);
    if (ssd.matched){
        std::cout << "There is a match: " << std::endl;
        std::cout << num_list[ssd.first_to_match] << " + " << num_list[ssd.second_to_match] << " = " << target << std::endl;
    }
    else{
        std::cout << "There is no match" << std::endl;
    }
    return 0;
}

void initData(std::vector<int> &num_list, int &target, const int &argc, const char *argv[]){
    if (argc > 2){
        num_list.reserve(argc);
        for (int i = 2; i < argc; ++i){
            num_list.emplace_back(std::atoi(argv[i]));
        }
        target = std::atoi(argv[1]);
    }
    else{
        const int kdefault_lenght = std::rand() % 10 + 2;
        num_list.reserve(kdefault_lenght);
        for (int i = 0; i < kdefault_lenght; ++i){
            num_list.emplace_back(std::rand() % 100);
        }
        target = std::rand() % 200;
    }
}

std::string printVector(const std::vector<int> &p_vector, const std::string &separator){
    std::stringstream ss;
    for (const int i : p_vector){
        ss << i << separator;
    }
    return ss.str();
}