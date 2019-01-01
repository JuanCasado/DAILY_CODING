#include <sstream>
#include <iostream>

#include "FIRST_MISSING_POSITIVE.hpp"

std::string printVector(const std::vector<int> &p_vector, const std::string &separator);
void initData(std::vector<int> &p_vector, const int &argc, const char *argv[]);

int main(int argc, char const *argv[]) {
	std::vector<int> v;

	initData (v, argc, argv);
	std::cout << "[" << printVector(v, ", ") << "]" << std::endl;
	std::cout << firstMissingPositive(v) << std::endl;

	return 0;
}

std::string printVector(const std::vector<int> &p_vector, const std::string &separator){
    std::stringstream ss;
    for (const int i : p_vector){
        ss << i << separator;
    }
    return ss.str();
}

void initData(std::vector<int> &num_list, const int &argc, const char *argv[]){
    if (argc > 1){
    	num_list.reserve(argc);
        for (int i = 1; i < argc; ++i){
            num_list.emplace_back(std::atoi(argv[i]));
        }
    }
    else{
    	const int kdefault_lenght = std::rand() % 10 + 2;
    	num_list.reserve(kdefault_lenght);
        for (int i = 0; i < kdefault_lenght; ++i){
            num_list.emplace_back(std::rand() % 10 +1);
        }
    }
}