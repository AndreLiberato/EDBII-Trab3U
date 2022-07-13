#include <cstring>
#include "Util.hpp"

using namespace bt;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  notation_t prefix = readFile(file_prefix_in);
  notation_t postfix = readFile(file_postfix_in);

  check_dir(file_out_dir);

  std::fstream fs = openFile(file_aval_out);

  notation_t prefix_from_tree;
  notation_t postfix_from_tree;
  notation_t infix_from_tree;

  if(argc > 1 && (strcmp(argv[1], "--verbose") or strcmp(argv[1], "-v"))) {

    for (std::string expression : postfix){
      AvlTree* avlTree = new AvlTree();
      avlTree->from_postfix(avlTree->getRoot(), expression);
      avlTree->print(avlTree->getRoot());

      cout << "Original String:\t" << expression << endl;

      cout << "Posfix notation:\t" << avlTree->to_postfix(avlTree->getRoot()) << endl;
      prefix_from_tree.push_back(avlTree->to_postfix(avlTree->getRoot()));

      cout << "Prefix notation:\t" << avlTree->to_prefix(avlTree->getRoot()) << endl;
      postfix_from_tree.push_back(avlTree->to_prefix(avlTree->getRoot()));

      cout << "Infix notation: \t" << avlTree->to_infix(avlTree->getRoot()) << endl;
      infix_from_tree.push_back(avlTree->to_infix(avlTree->getRoot()));

      cout << "Result: \t" <<  calculator(avlTree->to_postfix(avlTree->getRoot())) << endl;
      fs << calculator(avlTree->to_postfix(avlTree->getRoot())) << "\n";
      delete avlTree;

    }
    std::cout << "_________________________________" << std::endl;
  }

  else {
    for (std::string expression : postfix){
      AvlTree* avlTree = new AvlTree();
      avlTree->from_postfix(avlTree->getRoot(), expression);

      postfix_from_tree.push_back(avlTree->to_postfix(avlTree->getRoot()));

      prefix_from_tree.push_back(avlTree->to_prefix(avlTree->getRoot()));

      infix_from_tree.push_back(avlTree->to_infix(avlTree->getRoot()));

      fs << calculator(avlTree->to_postfix(avlTree->getRoot())) << "\n";
      delete avlTree;
    }
  }

  writeFile(prefix_from_tree, file_prefix_out);
  writeFile(postfix_from_tree, file_postfix_out);
  writeFile(infix_from_tree, file_infix_out);

  fs.close();

  return 0;
}
