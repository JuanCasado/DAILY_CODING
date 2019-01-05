#include "XOR_LINKED_LIST.hpp"

XorLinkedList::ListNode *XorLinkedList::makeXor (const XorLinkedList::ListNode *a_ptr, const XorLinkedList::ListNode *b_ptr){
	return reinterpret_cast<XorLinkedList::ListNode*>((reinterpret_cast<uintptr_t>(a_ptr)) ^ (reinterpret_cast<uintptr_t>(b_ptr)));
}

void XorLinkedList::add (XorLinkedList::ListNode *new_node){
	if (_size == 0) {
		new_node->_xor_link = makeXor(nullptr,nullptr);
		head = new_node;
	} else {
		XorLinkedList::ListNode *looking_at = head;
		XorLinkedList::ListNode *key = nullptr;
		XorLinkedList::ListNode *obtained = nullptr;
		while ((obtained = makeXor(looking_at->_xor_link,key))!=nullptr){
			key = looking_at;
			looking_at = obtained;
		}
		obtained = makeXor(looking_at->_xor_link,nullptr);
		looking_at->_xor_link = makeXor(obtained, new_node);
		new_node->_xor_link = makeXor(looking_at,nullptr);
	}
	++_size;
}

XorLinkedList::ListNode *XorLinkedList::getAt(const int &pos){
	if ((pos>=0) && (pos < _size)){
		int index = 0;
		XorLinkedList::ListNode *looking_at = head;
		XorLinkedList::ListNode *key = nullptr;
		XorLinkedList::ListNode *obtained = nullptr;
		while (index < pos){
			obtained = makeXor(looking_at->_xor_link,key);
			key = looking_at;
			looking_at = obtained;
			++ index;
		}
		return looking_at;
	}
	return nullptr;
}

int XorLinkedList::size (){
	return _size;
}
