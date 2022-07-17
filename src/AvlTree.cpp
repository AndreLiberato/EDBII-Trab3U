#include "AvlTree.hpp"

using namespace avlt;
using std::cout;
using std::endl;

AvlTree::~AvlTree() { remove_node(root); }

AvlTree::Node* AvlTree::right_rotation(Node* root) {
  cout << "In right_rotation(). "
    << " node: " << root 
    << " node->key: " << root->key 
    << " node->bal: " << root->balance
    << endl;

  if (root != nullptr and root->left != nullptr) {
    Node* tempNode = new Node(0);
    *tempNode = *root;
    *root = *root->left;
    delete tempNode->left;
    tempNode->left = nullptr;
    root->right = tempNode;
    return root;
  }
  return nullptr;
}

AvlTree::Node* AvlTree::left_rotation(Node* root) {
  if (root != nullptr and root->right != nullptr) {
    Node* tempNode = new Node(0);
    *tempNode = *root;
    *root = *root->right;
    delete tempNode->right;
    tempNode->right = nullptr;
    root->left = tempNode;
    return root;
  }
  return nullptr;
}

AvlTree::Node* AvlTree::double_right_rotation(Node* root) {
  // Left rotation on the left subtree.
  Node* newLeftRoot = left_rotation(root->left);

  // Assign the rotated tree to be the new left subtree.
  root->left = newLeftRoot;

  // Right rotation on the root.
  Node* newRoot = right_rotation(root);
  return newRoot;
}

AvlTree::Node* AvlTree::double_left_rotation(Node* root) {
  // Right rotation on the right subtree.
  Node* newRightRoot = right_rotation(root->right);

  // Assign the rotated tree to be the new right subtree.
  root->right = newRightRoot;

  // Left rotation on the root.
  Node* newRoot = left_rotation(root);
  return newRoot;
}

void AvlTree::insert(int key, Node* node, bool* h) {
  if (key != node->key) {
    if (key < node->key) {
      if (node->left == nullptr) {
        node->left = new Node(key);
        *h = true;
      }
      insert(key, node->left, h);
      if (*h) {
        switch (node->balance) {
          case 1:
            node->balance = 0;
            *h = false;
            break;
          case 0:
            node->balance = -1;
            break;
          case -1:
            left_rebalance(node, h);
            break;
        }
      }
    }
    else {
      if (node->right == nullptr) {
        node->right = new Node(key);
        *h = true;
      }
      insert(key, node->right, h);
      if (*h) {
        switch (node->balance) {
          case -1:
            node->balance = 0;
            *h = false;
            break;
          case 0:
            node->balance = 1;
            break;
          case 1:
            right_rebalance(node, h);
            break;
        }
      }
    }
  }
}

void AvlTree::left_rebalance(Node* node, bool* h) {
  if ((node->left)->balance == -1) {
    node->balance = 0;
    cout << "Op right_rotation left_rebalance key: " << node->key << endl;
    right_rotation(node);
  }
  else {
    // Change the tree structure by a DRR.
    cout << "Op double_right_rotation left_rebalance key: " << node->key << endl;
    node = double_right_rotation(node);

    // Adjust the balance.
    if (node->balance == -1)
      (node->right)->balance = 1;
    else
      (node->right)->balance = 0;
    if (node->balance == 1)
      (node->left)->balance = -1;
    else
      (node->left)->balance = 0;
  }
  node->balance = 0;
  *h = false;
}

void AvlTree::right_rebalance(Node* node, bool* h) {
  if ((node->right)->balance == -1) {
    node->balance = 0;
    cout << "Op left_rotation right_rebalance key: " << node->key << endl;
    left_rotation(node);
  }
  else {
    // Change the tree structure by a DRR.
    cout << "Op double_left_rotation right_rebalance key: " << node->key << endl;
    node = double_left_rotation(node);

    // Adjust the balance.
    if (node->balance == -1)
      (node->right)->balance = 1;
    else
      (node->left)->balance = 0;
    if (node->balance == 1)
      (node->right)->balance = -1;
    else
      (node->right)->balance = 0;
  }
  node->balance = 0;
  *h = false;
}

void AvlTree::remove_node(Node* node) {
  if (node->left != nullptr)
    remove_node(node->left);

  if (node->right != nullptr)
    remove_node(node->right);

  delete node;
}

AvlTree::Node* AvlTree::getRoot() { return root; }

int AvlTree::visit(Node* node) {
  if (node != nullptr)
    return node->key;
  else
    return -1; // TODO: ajustar mensagem de erro!
}

// TODO: transformar isso em uma função que lê uma string de commando para
// criação da árvore.
std::string AvlTree::from_command(Node* node, std::string command) {
  if (!command.empty()) {
    if (is_operator(command.front())) {

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
  if (node != nullptr) {
    std::cout << "\033[0;33m" << prefix;
    std::cout << "\033[0m";

    std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──");
    std::cout << "\033[0m";

    // Print the value of the node
    std::cout << "\033[1;32m"
      << " " << node->key << "|" << node->balance << std::endl;
    std::cout << "\033[0m";

    // Enter the next tree level - left and right branch
    print(node->left, prefix + (isLeft ? "|   " : "    "), true);
    print(node->right, prefix + (isLeft ? "|   " : "    "), false);
  }
}
