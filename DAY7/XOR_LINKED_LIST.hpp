#ifndef XOR_LINKED_LIST_HPP
#define XOR_LINKED_LIST_HPP
#include <string>
#include <memory>

class XorLinkedList {
public:
	struct ListNode {
		std::string value;
		ListNode *_xor_link = nullptr;
	};
	void add (ListNode*new_node);
	ListNode *getAt(const int &pos);
	int size ();
private:
	ListNode *head = nullptr;
	int _size = 0;
	static ListNode *makeXor (const ListNode *a_ptr,const ListNode *b_ptr);
};

#endif

/*
int *XOR (int *a_ptr, int *b_ptr){
	return (int*) ((uintptr_t) (a_ptr) ^ (uintptr_t) (b_ptr));
}
std::unique_ptr<int> *XOR (std::unique_ptr<int> &a_ptr, std::unique_ptr<int> &b_ptr){
	return (std::unique_ptr<int>*) ((uintptr_t) (&a_ptr) ^ (uintptr_t) (&b_ptr));
}
void demo () {
	//PLAYING WITH POINTERS
	int a = 3;
	int b = 4;

	int *a_ptr = &a;
	int *b_ptr = &b;
	int *xor_ptr = XOR(a_ptr, b_ptr);

	std::cout << "PTR$ a: " << *XOR(xor_ptr, b_ptr) << " b: " << *XOR(xor_ptr, a_ptr) << std::endl;

	std::unique_ptr<int> a_unique = std::make_unique<int>(a);
	std::unique_ptr<int> b_unique = std::make_unique<int>(b);
	std::unique_ptr<int> *xor_unique = XOR(a_unique, b_unique);

	std::cout << "UNIQUE$ a: " << **XOR(*xor_unique,b_unique) << " b: " << **XOR(*xor_unique,a_unique) << std::endl;
//--------------------------------------------------------------------------------------------------------------------------
	//TRANFERING OWNERSHIP
	std::unique_ptr<int> unique = std::make_unique<int>(1);
	std::cout << "UNIQUE: " << *unique << std::endl;

	std::shared_ptr<int> shared = std::make_shared<int>(*unique.release());
	std::cout << "SHARED: " << *shared << std::endl;
}

*/
