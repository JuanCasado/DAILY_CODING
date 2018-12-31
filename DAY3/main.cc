#include <iostream>

#include "SORTED_FROM_SORTEDS.hpp"

void initData (std::vector<std::unique_ptr<std::vector<int>>> &p_vectors, const int argc, const char  *const argv[]);
std::string printVector(const std::unique_ptr<std::vector<int>> &p_vector, const std::string &separator);
std::string printVector(const std::vector<int> &p_vector, const std::string &separator);

int main(int argc, char const *argv[]) {
	std::vector<std::unique_ptr<std::vector<int>>> data;
	initData(data,argc,argv);
	
	std::cout << "initial data:" << std::endl;
	for (const auto &vector : data){
		std::cout << "\t[" << printVector(vector, ", ") << "]" << std::endl;
	}
	sortListOfList(data);
	std::cout << "sorted data:" << std::endl;
	for (const auto &vector : data){
		std::cout << "\t[" << printVector(vector, ", ") << "]" << std::endl;
	}
	std::vector<int> result;
	mergeSorted(std::move(data), result);
	std::cout << "SingleSorted: [" << printVector(result, ", ") << "]" << std::endl;

	return 0;
}

void initData (std::vector<std::unique_ptr<std::vector<int>>> &p_vectors, const int argc, const char *const argv[]){
	if (argc > 1){
		int acc_size = 1;
		int read_index = 1;
		int elem_num = 0;
		bool control = true;
		while (control){
			elem_num = std::atoi(argv[read_index]);
			acc_size += elem_num + 1;
			++read_index;
			if (acc_size <= argc){
				std::unique_ptr<std::vector<int>> list = std::make_unique<std::vector<int>>(std::vector<int>{});
				list->reserve(elem_num);
				for (;read_index < acc_size; ++read_index){
					list->emplace_back (std::atoi(argv[read_index]));
				}
				p_vectors.emplace_back(std::move(list));
				if (read_index >= argc){
					control = false;
				}
			} else {
				control = false;
			}
		}
	}else{
		const int ksize = std::rand()%5 +1;
		p_vectors.reserve (ksize);
		for (int i = 0; i < ksize; ++i){
			std::unique_ptr<std::vector<int>> list = std::make_unique<std::vector<int>>(std::vector<int>{});
			const int ksize_inner = std::rand()%10 +1;
			list->reserve (ksize_inner);
			for (int i = 0; i < ksize_inner; ++i){				
				list->emplace_back(std::rand()%50);
			}
			p_vectors.emplace_back(std::move(list));
		}
	}
}

std::string printVector(const std::unique_ptr<std::vector<int>> &p_vector, const std::string &separator){
    std::stringstream ss;
    for (const int i : *p_vector){
        ss << i << separator;
    }
    return ss.str();
}

std::string printVector(const std::vector<int> &p_vector, const std::string &separator){
    std::stringstream ss;
    for (const int i : p_vector){
        ss << i << separator;
    }
    return ss.str();
}
