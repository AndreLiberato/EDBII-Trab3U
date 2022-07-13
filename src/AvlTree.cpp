#include "AvlTree.hpp"

using namespace bt;

AvlTree::~AvlTree() {
  remove_node(root);
}

void AvlTree::remove_node(Node* node) {
  if(node->left != nullptr)
    remove_node(node->left);

  if(node->right != nullptr)
    remove_node(node->right);

  delete node;
}

AvlTree::Node* AvlTree::getRoot() {
  return root;
}

std::string AvlTree::visit(Node* node) {
  if(node != nullptr) 
    return node->data;
  else
    return "ERROR"; // TODO: dá pra melhorar isso!
}

std::string AvlTree::from_postfix(Node* node, std::string postfix) {
  if( !postfix.empty() ) {
    if( is_operator(postfix.back()) ) {
      /* 
       * Note: To build a binary tree using postfix notation, 
       * use preorder traversal on right first
       */

      node->right = new Node();
      node->left = new Node();

      node->data = postfix.back();

      postfix.pop_back();
      postfix.pop_back();
      postfix = from_postfix(node->right, postfix);
      postfix = from_postfix(node->left, postfix);
      return postfix;
    }

    else {

      std::string delim = " ";
      std::string number;

      size_t pos = 0;
      if ( ( pos = postfix.find_last_of(delim) ) != std::string::npos ) {
        node->data = postfix.substr(pos+1, postfix.length());
        postfix.erase(pos, postfix.length());
      }
      else {
        node->data = postfix.substr(0, postfix.length());
        postfix.erase(0, postfix.length());
      }

      return postfix;
    }
  }
  return "";
}

std::string AvlTree::from_prefix(Node* node, std::string prefix) {
  if( !prefix.empty() ) {
    if( is_operator( prefix.front() )) {
      /* 
       * Note: To build a binary tree using prefix notation, 
       * use preorder traversal on right first
       */

      node->left = new Node();
      node->right = new Node();

      node->data = prefix.front();

      prefix.erase(prefix.begin());

      prefix = from_prefix(node->left, prefix);
      prefix = from_prefix(node->right, prefix);

      return prefix;
    }

    else {
      node->data = prefix.front();

      prefix.erase(prefix.begin());

      return prefix;
    }
  }
  return "";
}

std::string AvlTree::to_postfix(Node* node, std::string postfix) {
  //In postfix, first access the subtree on the left
  if (node->left != nullptr)
    postfix += to_postfix(node->left);

  //then on the right
  if (node->right != nullptr)
    postfix += to_postfix(node->right);

  //and then visit the node.
  postfix += visit(node) + " ";

  //postfix.pop_back();
  
  return postfix;
}

std::string AvlTree::to_prefix(Node* node, std::string prefix) {
  prefix += visit(node) + " ";

  if (node->left != nullptr)
    prefix += to_prefix(node->left);

  if (node->right != nullptr)
    prefix += to_prefix(node->right);

  return prefix;
}

std::string AvlTree::to_infix(Node* node, std::string infix) {
  // Checks if the node is a leaf or root.
  infix += (
      ((node->left == nullptr && node->right == nullptr) 
       || node == root) ? "" : "(" 
      );

  if(node->left != nullptr)
    infix += to_infix(node->left);

  infix += visit(node);

  if(node->right != nullptr)
    infix += to_infix(node->right);

  // Checks if the node is a leaf or root.
  infix += (
      ((node->left == nullptr && node->right == nullptr) 
       || node == root) ? "" : ")"
      );
  return infix;
}

void AvlTree::print(Node* node, std::string prefix, bool isLeft) {
  if(node != nullptr) {
    std::cout << "\033[0;33m" << prefix;
    std::cout << "\033[0m";

    std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──" );
    std::cout << "\033[0m";

    // Print the value of the node
    std::cout << "\033[1;32m" << " " << node->data << std::endl;
    std::cout << "\033[0m";

    // Enter the next tree level - left and right branch
    print(node->left, prefix + (isLeft ? "|   " : "    "), true);
    print(node->right, prefix + (isLeft ? "|   " : "    "), false);
  }
}
