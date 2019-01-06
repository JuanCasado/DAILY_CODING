# DAILY_CODING
every day a new coding challenge!!!

* **DAY1**: Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

* **DAY2**: Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i. 
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

* **DAY3**: return a new sorted merged list from K sorted lists, each with size N.
For example, if we had [[10, 15, 30], [12, 15, 20], [17, 20, 32]], the result should be [10, 12, 15, 15, 17, 20, 20, 30, 32]. 

* **DAY4**: Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
For example, given the following Node class

            class Node:
                def __init__(self, val, left=None, right=None):
                self.val = val
                self.left = left
                self.right = right
            #The following test should pass:
	    node = Node('root',Node('left',Node('left.left')),
	    Node('right'))assertdeserialize(serialize(node)).left.left.val == 'left.left' 

* **DAY5**: Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.You can modify the input array in-place.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3. 

* **DAY6**: cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

		#Given this implementation of cons:
		
		def cons(a, b):
		    def pair(f):
		        return f(a, b)
		    return pair
		
		#Implement car and cdr.

* **DAY7**: An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses. 

* **DAY8**: Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
You can assume that the messages are decodable. For example, '001' is not allowed. 

* **DAY9**: A unival tree (which stands for universal value) is a tree where all nodes under it have the same value.
Given the root to a binary tree, count the number of unival subtrees.
For example, the following tree has 5 unival subtrees:

		     0
		    /  \       
		    1   0
		       / \
		      1   0
		     / \
		    1   1 
