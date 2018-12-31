#ifndef SORTED_FROM_SORTEDS_HPP
#define SORTED_FROM_SORTEDS_HPP
#include <vector>
#include <algorithm>
#include <memory>
#include <sstream>

//To make the heap a min heap
struct HeapElement{
	int value = 0;
	int from_list = 0;
	int with_index = 0;
	bool operator() (const HeapElement& a,const HeapElement& b) const{ 
    	return a.value>b.value; 
	}
	bool operator() (const std::unique_ptr<HeapElement> &a,const std::unique_ptr<HeapElement> &b) const{ 
    	return a->value>b->value; 
	}
	std::string print() {
		std::stringstream ss;
		ss << value << ", ";
		ss << from_list << ", ";
		ss << with_index;
		return ss.str();
	}
};

void sortListOfList(std::vector<std::unique_ptr<std::vector<int>>> &p_vector);
void mergeSorted(std::vector<std::unique_ptr<std::vector<int>>> &&p_vector, std::vector<int> &result);

#endif
