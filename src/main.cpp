#include "Util.hpp"
#include <cstring>

using namespace avlt;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

  AvlTree* avlTree = new AvlTree();
  avlTree->insert(5, avlTree->getRoot(), true);
  //std::cout << (((avlTree->getRoot())->right)->key) << std::endl;
  avlTree->print(avlTree->getRoot());
  delete avlTree;

  return 0;
}
