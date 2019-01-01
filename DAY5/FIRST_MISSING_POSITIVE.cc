#include "FIRST_MISSING_POSITIVE.hpp"

#include <iostream>

int moveToLeft (std::vector<int> &data, int from){
	int max_swaped = 0;
	for (int i = 0; i < data.size(); ++i){
		if (data[i] < from) {
			std::swap (data[i], data [max_swaped]);
			++max_swaped;
		}
	}
	return max_swaped;
}

int firstMissingPositive (std::vector<int> &data, int from){
	const int fisrt_over_value = moveToLeft (data, from);
	int max_marked = fisrt_over_value;
	int abs_value = 0;
	for (int i = fisrt_over_value; i < data.size(); ++i){
		abs_value = abs(data[i]) + max_marked - 1;
		if (abs_value < data.size()){
			data [abs_value] *= -1;
		}
	}
	for (int i = fisrt_over_value; i < data.size(); ++i){
		if (data[i] > 0){
			return i - fisrt_over_value + 1;
		}
	}
	return data.size() - fisrt_over_value + 1;
}