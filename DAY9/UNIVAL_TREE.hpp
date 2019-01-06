#ifndef UNIVAL_TREE_HPP
#define UNIVAL_TREE_HPP
#include <vector>
#include <string>
#include <sstream>
#include <memory>

class Tree {
	public :
		enum Branch{
			kleft,
			kright
		};
		std::string serialize ();
		static std::unique_ptr<Tree> unSerialize (const std::string &tree);
		void addNode (const std::string &node_attachment,const std::string &new_node, const Branch &branch);
		std::string draw(std::string indent = "", bool first = true);
		Tree (const std::string &val, std::unique_ptr<Tree> &&left = nullptr, std::unique_ptr<Tree> &&right = nullptr) : _val(val), _left(std::move(left)), _right(std::move(right)) {}
		int countUnival ();
		int countLeafs ();
	private:
		int countUnival (bool &isUnival);
		static const std::string kseparator;
		static const std::string knode_null;
		std::string _val;
		std::unique_ptr<Tree> _left;
		std::unique_ptr<Tree>  _right;
		void attachNode (const std::string &new_node, const Branch &branch);
		static std::vector<std::string> parseTreeString (std::string tree);
};

#endif
