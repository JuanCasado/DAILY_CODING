# DAILY_CODING
every day a new code challenge!!!

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
                
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left' 

* **DAY5**: Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.You can modify the input array in-place.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3. 
