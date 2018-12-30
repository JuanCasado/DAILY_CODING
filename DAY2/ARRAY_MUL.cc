#include "ARRAY_MUL.hpp"

void mulExceptSelf(const std::vector<int> &data, std::vector<int> &result){
	int mul_buffer = 1;
	result.reserve(data.size());
	for (int i = 0; i < data.size(); ++i){
		result.emplace_back(mul_buffer);
		mul_buffer *= data[i];
	}
	mul_buffer = 1;
	for (int i = data.size()-1; i >= 0; --i){
		result[i] *= mul_buffer;
		mul_buffer *= data[i];
	}
}