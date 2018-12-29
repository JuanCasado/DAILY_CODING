#include "SUM_SEARCH.hpp"

int main(int argc, char const *argv[]){
    std::vector<int> num_list;
    const int kdefault_lenght = std::rand()%10 +2;
    int target;
    if (argc > 2){
        for (int i = 2; i < argc; ++i){
            num_list.emplace_back(std::atoi(argv[i]));
        }
        target = std::atoi(argv[1]);
    }else{
        for (int i = 0; i < kdefault_lenght; ++i){
            num_list.emplace_back(std::rand()%100);
        }
        target = std::rand() % 200;
    }
    std::cout << "Target: " << target << std::endl;
    std::cout << "Initial data: [";
    printVector (num_list, ", ");
    std::cout << "]" << std::endl;

    std::sort(num_list.begin(), num_list.end());

    std::cout << "Sorted data: [";
    printVector(num_list, ", ");
    std::cout << "]" << std::endl;

    SumSearchData ssd;
    sumSeach(target,num_list,ssd);

    if (ssd.matched){
        std::cout << "There is a match: " << std::endl;
        std::cout << num_list[ssd.first_to_match] << " + " << num_list[ssd.second_to_match] << " = " << target << std::endl;
    }else{
        std::cout << "There is no match" << std::endl;
    }
    return 0;
}

void printVector (const std::vector<int> &p_vector, const std::string &separator){
    for (const int i : p_vector){
        std::cout << i << separator;
    }
}

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