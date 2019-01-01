#include <iostream>

#include "SERIALIZE_TREE.hpp"


int main(int argc, char const *argv[]) {
	
	std::unique_ptr<Tree> root = std::make_unique<Tree>(Tree{"root"});
	root->addNode("root", "left", Tree::Branch::kleft);
	root->addNode("left", "left.left", Tree::Branch::kleft);
	root->addNode("left", "left.right", Tree::Branch::kright);
	root->addNode("root", "right", Tree::Branch::kright);
	root->addNode("right", "right.left", Tree::Branch::kleft);
	root->addNode("right", "right.right", Tree::Branch::kright);
	root->addNode("right.right", "right.right.right", Tree::Branch::kright);

	std::cout << Tree::unSerialize(root->serialize())->serialize() << std::endl;
	
	std::cout << root->draw() << std::endl;
	return 0;
}
