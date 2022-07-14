#include "AvlTree.hpp"

using namespace avlt;

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

int AvlTree::visit(Node* node) {
  if(node != nullptr) 
    return node->key;
  else
    return -1; // TODO: ajustar mensagem de erro!
}

// TODO: transformar isso em uma função que lê uma string de comando para criação da árvore.
std::string AvlTree::from_command(Node* node, std::string command) {
  if( !command.empty() ) {
    if( is_operator( command.front() )) {

      node->left = new Node(0);
      node->right = new Node(0);

      node->key = command.front();

      command.erase(command.begin());

      command = from_command(node->left, command);
      command = from_command(node->right, command);

      return command;
    }

    else {
      node->key = command.front();

      command.erase(command.begin());

      return command;
    }
  }
  return "";
}

void AvlTree::print(Node* node, std::string prefix, bool isLeft) {
  if(node != nullptr) {
    std::cout << "\033[0;33m" << prefix;
    std::cout << "\033[0m";

    std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──" );
    std::cout << "\033[0m";

    // Print the value of the node
    std::cout << "\033[1;32m" << " " << node->key << std::endl;
    std::cout << "\033[0m";

    // Enter the next tree level - left and right branch
    print(node->left, prefix + (isLeft ? "|   " : "    "), true);
    print(node->right, prefix + (isLeft ? "|   " : "    "), false);
  }
}
