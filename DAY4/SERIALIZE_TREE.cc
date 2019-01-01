#include "SERIALIZE_TREE.hpp"

const std::string Tree::kseparator = " ";
const std::string Tree::knode_null = "nullptr";

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
std::unique_ptr<Tree> Tree::unSerialize (std::string tree){
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
		}
	} else if (branch==Branch::kright) {
		if (!this->_right){
			this->_right = std::make_unique<Tree>(Tree{new_node});
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
