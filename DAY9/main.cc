#include "UNIVAL_TREE.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
	std::unique_ptr<Tree> root = std::make_unique<Tree>(Tree{"root"});
	root->addNode("root", "left", Tree::Branch::kleft);
	root->addNode("root", "node", Tree::Branch::kright);
	root->addNode("node", "right", Tree::Branch::kright);
	root->addNode("node", "left", Tree::Branch::kleft);
	root->addNode("right", "right", Tree::Branch::kright);
	root->addNode("right", "right", Tree::Branch::kleft);
	std::cout << root->draw() << std::endl;
	std::cout << root->countUnival() << std::endl;
	return 0;
}
