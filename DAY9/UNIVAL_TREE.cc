#include "UNIVAL_TREE.hpp"

const std::string Tree::kseparator = " ";
const std::string Tree::knode_null = "nullptr";

int Tree::countUnival () {
	bool clildIsUnival = false;
	return this->countUnival(clildIsUnival);
}

int Tree::countUnival (bool &isUnival) {
	std::cout << this->_val << std::endl;
	if ((!this->_left) && (!this->_right)) {
		isUnival = true;
		return 1;
	} else if (!this->_left) {
		bool clildIsUnival = false;
		const int unival_count = this->_right->countUnival(clildIsUnival);
		if (clildIsUnival && (this->_val == this->_right->_val)){
			isUnival = true;
			return unival_count + 1;
		}
		return unival_count;
	} else if (!this->_right) {
		bool clildIsUnival = false;
		const int unival_count = this->_left->countUnival(clildIsUnival);
		if (clildIsUnival && (this->_val == this->_left->_val)) {
			return unival_count + 1;
			isUnival = true;
		}
		return unival_count;
	} else {
		bool clild1IsUnival = false;
		bool clild2IsUnival = false;
		const int unival_count = this->_right->countUnival(clild1IsUnival) + this->_left->countUnival(clild2IsUnival);
		if (clild1IsUnival && clild2IsUnival){
			if (this->_left && (this->_val != this->_left->_val)) {
				isUnival = false;
				return unival_count;
			}
			else if (this->_right && (this->_val != this->_right->_val)){
				isUnival = false;
				return unival_count;
			}
			isUnival = true;
			return unival_count + 1;
		}
		isUnival = false;
		return unival_count;
	}
	return 0;
}

int Tree::countLeafs () {
	if (!this->_left && !this->_right) {
		return 1;
	} else if (!this->_left) {
		return this->_right->countUnival();
	} else if (!this->_right) {
		return this->_left->countUnival();
	} else {
		return this->_right->countUnival() + this->_left->countUnival();
	}
	return 0;
}

std::string Tree::serialize (){
	std::stringstream ss;
	ss << this->_val << kseparator;
	if (_left)
		ss << this->_left->_val << kseparator;
	else
		ss << knode_null << kseparator;
	if (_right)
		ss << this->_right->_val << kseparator;
	else
		ss << knode_null << kseparator;
	if (_left)
		ss << this->_left->serialize();
	if (_right)
		ss << this->_right->serialize();
	return ss.str();
}
std::unique_ptr<Tree> Tree::unSerialize (const std::string &tree){
	std::vector<std::string> parsed_tree = parseTreeString(tree);
	const int kstep = 3;
	int start = 3;	
	std::unique_ptr<Tree> root;
	if (parsed_tree.size() > start){
		root = std::make_unique<Tree>(Tree{parsed_tree[0]});
		root->addNode(parsed_tree[0], parsed_tree[1], Tree::Branch::kleft);
		root->addNode(parsed_tree[0], parsed_tree[2], Tree::Branch::kright);
	}
	while (parsed_tree.size() > (start + kstep)){
		if (parsed_tree[start+1]!=knode_null)
			root->addNode(parsed_tree[start], parsed_tree[start+1], Tree::Branch::kleft);
		if (parsed_tree[start+2]!=knode_null)
			root->addNode(parsed_tree[start], parsed_tree[start+2], Tree::Branch::kright);
		start += kstep;
	}
	return root;
}

void Tree::addNode (const std::string &node_attachment, const std::string &new_node, const Branch &branch){
	if (this->_val == node_attachment){
		this->attachNode(new_node, branch);
	} else {
		if (this->_left) {
			this->_left->addNode(node_attachment, new_node, branch);
		}
		if (this->_right) {
			this->_right->addNode(node_attachment, new_node, branch);
		}
	}
}

void Tree::attachNode (const std::string &new_node, const Branch &branch){
	if (branch==Branch::kleft){
		if (!this->_left){
			this->_left = std::make_unique<Tree>(Tree{new_node});
		} else {
			this->_left->addNode(this->_val, new_node, branch);
		}
	} else if (branch==Branch::kright) {
		if (!this->_right){
			this->_right = std::make_unique<Tree>(Tree{new_node});
		} else {
			this->_right->addNode(this->_val, new_node, branch);
		}
	}
}

std::vector<std::string> Tree::parseTreeString (std::string tree){
	std::vector<std::string> parsed_tree;
    auto start = 0U;
    auto end = tree.find(Tree::kseparator);
    std::string token;
    while (end != std::string::npos){
    	token = tree.substr(start, end - start);
    	if (token.length()){
	        parsed_tree.emplace_back(token);
	    }
        start = end + kseparator.length();
        end = tree.find(kseparator, start);
    }
    return parsed_tree;
}

std::string Tree::draw(std::string indent, bool first){
	std::stringstream ss;
	if (!first){
		ss << "╠═";
		ss << this->_val << std::endl;
		if (this->_right==nullptr && this->_left==nullptr){
			indent.append("  ");
		} else {
			indent.append("║  ");
		}
	} else {
		ss << this->_val << std::endl;
	}
	if (this->_left){
		ss << indent <<_left->draw(indent, false);
	} else{
		ss << indent << "╚═ *" << std::endl;
	}
	if (this->_right){
		ss << indent << _right->draw(indent, false);
	}
	else{
		ss << indent << "╚═ *" << std::endl;	
	}
	return ss.str();
}