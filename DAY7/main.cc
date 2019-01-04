#include "XOR_LINKED_LIST.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
	XorLinkedList list{};
	list.add(new XorLinkedList::ListNode{"valor0"});
	list.add(new XorLinkedList::ListNode{"valor1"});
	list.add(new XorLinkedList::ListNode{"valor2"});
	list.add(new XorLinkedList::ListNode{"valor3"});
	std::cout << "READING:" << std::endl;
	std::cout << list.getAt(2)->value << std::endl;
	
	return 0;
}
