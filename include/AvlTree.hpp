#ifndef BINTREE_HPP_
#define BINTREE_HPP_

#include <iostream>
#include <string>
#include "Util.hpp"

namespace avlt {
  class AvlTree {
    private:
      struct Node{
        std::string data; //!< The information we want to store in the node.
        Node* left;       //!< A pointer to the left node in the list.
        Node* right;      //!< A pointer to the right node in the list.

        //! Default Ctro.
        Node(const char &d=char{}, Node* l=nullptr, Node* r=nullptr)
          : data {d}, left{l}, right{r}
        { /*empty*/ }
      };

      Node* root;  //!< The root node.

    public:
      // @brief The class constructor.
      AvlTree(Node* r=new Node('-'))
        : root{r}
      { /*empty*/ }

      // @brief The class destructor.
      ~AvlTree();

      /*
       * @brief Recursively removes the node from memory with all its sub-nodes.
       * @param A pointer to a node.
       */
      void remove_node(Node* node);

      /*
       * @brief Gives the root node of the tree.
       * @return The root node of the tree.
       */
      Node* getRoot();

      /*
       * @brief Gives the data value of the node.
       * @param node: a arbitrary node.
       * @return The data in the node.
       */
      std::string visit(Node* node);


      /*
       * @brief Gets a string in postfix notation and converts it to a binary tree.
       * @param postfix: a string containing the postfix notation.
       */
      std::string from_postfix(Node* node, std::string postfix);


      /*
       * @brief Gets a string in prefix notation and converts it to a binary tree.
       * @param prefix: a string containing the prefix notation.
       */
      std::string from_prefix(Node* node, std::string prefix);

      /* 
       * @brief Gets a string containing the postfix notation for the tree.
       * @param postfix: just a variable to write the postfix notation in.
       * @param node an Node containing the node that the tree is going to start to be converted. 
       * @return A string containing the postfix notation.
       */
      std::string to_postfix(Node* node, std::string postfix="");


      /* 
       * @brief Gives the prefix representation of the tree.
       * @return An string containing the tree's representation in prefix notation.
       */
      std::string to_prefix(Node* node, std::string prefix="");

      /* 
       * @brief Gives the infix representation of the tree.
       * @return An string containing the tree's representation in infix notation. 
       */
      std::string to_infix(Node* node, std::string infix="");


      /* 
       * @brief Prints the binary tree in a nice way.
       * @param node an Node containing the node that the tree is going to start to be printed. 
       * @param prefix a string to help indent the tree.
       * @param isLeft a bool to just to see if the node is a left one.
       */
      void print(Node* node, std::string prefix="", bool isLeft=false);

  };
}

#endif // BINTREE_HPP_
