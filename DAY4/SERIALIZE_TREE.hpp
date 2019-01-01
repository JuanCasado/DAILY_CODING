#ifndef SERIALIZE_TREE_HPP
#define SERIALIZE_TREE_HPP
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
		static std::unique_ptr<Tree> unSerialize (std::string tree);
		void addNode (const std::string &node_attachment,const std::string &new_node, const Branch &branch);
		std::string draw(std::string indent = "", bool first = true);
		Tree (std::string val, std::unique_ptr<Tree> &&left = nullptr, std::unique_ptr<Tree> &&right = nullptr) : _val(val), _left(std::move(left)), _right(std::move(right)) {}
	private:
		static const std::string kseparator;
		static const std::string knode_null;
		std::string _val;
		std::unique_ptr<Tree> _left;
		std::unique_ptr<Tree>  _right;
		void attachNode (const std::string &new_node, const Branch &branch);
		static std::vector<std::string> parseTreeString (std::string tree);
};

#endif
