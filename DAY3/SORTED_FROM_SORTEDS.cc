#include "SORTED_FROM_SORTEDS.hpp"
#include<iostream>

void sortListOfList(std::vector<std::unique_ptr<std::vector<int>>> &p_vector){
	for (int i = 0; i < p_vector.size(); ++i){
		if (!p_vector[i]->size()){
			p_vector.erase(p_vector.begin()+i);
		}else{
			std::sort(p_vector[i]->begin(), p_vector[i]->end());
		}
	}
}
void mergeSorted(std::vector<std::unique_ptr<std::vector<int>>> &&p_vector, std::vector<int> &result){
	std::vector<std::unique_ptr<HeapElement>> vector;
	int total_size = 0;
	for (auto &list : p_vector){
		total_size += list->size();
	}
	vector.reserve(p_vector.size());
	result.reserve(total_size);
	for (int i = 0; i < p_vector.size(); ++i){
		if (p_vector[i]->size()>0){
			vector.emplace_back(std::make_unique<HeapElement>(HeapElement{p_vector[i]->at(0), i, 1}));
		}
	}
	std::make_heap(vector.begin(), vector.end(), HeapElement());
	for (int i = 0; i < total_size; ++i){
		std::pop_heap(vector.begin(), vector.end(), HeapElement());
		if (vector.size()){
			std::unique_ptr<HeapElement> lastElemet = std::move(vector.back());
			result.emplace_back(lastElemet->value);
			vector.pop_back();
			if (lastElemet->with_index < p_vector[lastElemet->from_list]->size()){
				vector.emplace_back(std::make_unique<HeapElement>(HeapElement{p_vector[lastElemet->from_list]->at(lastElemet->with_index), lastElemet->from_list, lastElemet->with_index+1}));
				std::push_heap(vector.begin(), vector.end(), HeapElement());
			}
		}
	}
}