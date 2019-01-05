#include "TREE_OF_POSSIBILITIES.hpp"

int claculatePosibilities (const std::vector<int> &message, const int &index){
	switch (message.size() - index){
		case 0:{
			return 0;
		}break;
		case 1:{
			return 1;
		}break;
		case 2:{
			return 1 + isValid(message[index],message[index+1]);
		}break;
		default:{
			const bool is_valid = isValid(message[index],message[index+1]);
			return (claculatePosibilities(message, index + 1) * is_valid) + (claculatePosibilities(message, index + 2) * is_valid);
		}
	}
}

int isValid (const int &num_1, const int &num_2){
	const int value = num_1 + num_2*10;
	return ((value >= 0) && (value <= 26));
}