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
    tempNode->left = root->right;
    root->right = tempNode;
    return root;
  }
  return nullptr;
}

AvlTree::Node* AvlTree::left_rotation(Node* root) {
    cout << "In left_rotation(). "
      << " node: " << root 
      << " node->key: " << root->key 
      << " node->bal: " << root->balance
      << endl;

  if (root != nullptr and root->right != nullptr) {
    Node* tempNode = new Node(0);
    *tempNode = *root;
    *root = *root->right;
    delete tempNode->right;
    tempNode->right = root->left;
    root->left = tempNode;
    return root;
  }
  return nullptr;
}

AvlTree::Node* AvlTree::double_right_rotation(Node* root) {
  cout << "In double_right_rotation(). "
    << " node: " << root 
    << " node->key: " << root->key 
    << " node->bal: " << root->balance
    << endl;

  // Left rotation on the left subtree.
  Node* newLeftRoot = left_rotation(root->left);

  // Assign the rotated tree to be the new left subtree.
  root->left = newLeftRoot;

  // Right rotation on the root.
  Node* newRoot = right_rotation(root);
  return newRoot;
}

AvlTree::Node* AvlTree::double_left_rotation(Node* root) {
  cout << "In double_left_rotation(). "
    << " node: " << root 
    << " node->key: " << root->key 
    << " node->bal: " << root->balance
    << endl;

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

void AvlTree::remove(int key, Node* root, bool* h) {
  Node* node = search(key, root);
  if (node != nullptr) {
    node = node->left;
  }
}


void AvlTree::left_rebalance(Node* node, bool* h) {
  cout << "In left_rebalance(). "
    << " node: " << root 
    << " node->key: " << root->key 
    << " node->bal: " << root->balance
    << "h: " << *h
    << endl;

  if ((node->left)->balance == -1) {
    node->balance = 0;
    right_rotation(node);
  }
  else {
    // Change the tree structure by a DRR.
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
  cout << "In right_rebalance(). "
    << " node: " << root 
    << " node->key: " << root->key 
    << " node->bal: " << root->balance
    << "h: " << *h
    << endl;

  if ((node->right)->balance == 1) {
    node->balance = 0;
    left_rotation(node);
  }
  else {
    // Change the tree structure by a DRR.
    node = double_left_rotation(node);

    // Adjust the balance.
    if (node->balance == 1)
      (node->left)->balance = -1;
    else
      (node->left)->balance = 0;
    if (node->balance == -1)
      (node->right)->balance = 1;
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

AvlTree::Node* AvlTree::search(int key, AvlTree::Node* root) {
  if (root->key == key) {
    print(root);
    return root;
  } else {
    if (root->left != nullptr and key < root->key) {
      return search(key, root->left);
    } else if (root->right != nullptr and key > root->key) {
      return search(key, root->right);
    }
  }
  return nullptr;
}
