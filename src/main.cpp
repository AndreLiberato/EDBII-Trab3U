#include "Util.hpp"
#include <cstring>

using namespace avlt;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

  AvlTree *avlTree = new AvlTree();
  std::string command = "I4";
  avlTree->from_command(avlTree->getRoot(), command);
  avlTree->print(avlTree->getRoot());
  delete avlTree;

  return 0;
}
