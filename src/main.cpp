#include "Util.hpp"
#include "Command.hpp"

using namespace avlt;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  std::string entry;
  std::string command;
  std::string value;
  Command command_sys;

  while (true)
  {
    std::cout << "avlt_cli> ";
    std::getline(std::cin, entry);

    command = split(entry).front();
    value = split(entry).back();

    switch (command_sys.get_command(command)) {
    case command_sys.insert:
      //
      std::cout << "insert" << std::endl;
      break;
    case command_sys.remove:
      //
      std::cout << "remove" << std::endl;
      break;
    case command_sys.list:
      //
      std::cout << "list" << std::endl;
      break;
    case command_sys.select:
      //
      std::cout << "select" << std::endl;
      break;
    case command_sys.exit:
      //
      std::cout << "exit" << std::endl;
      return EXIT_SUCCESS;
      break;

    default:
      std::cout << "Command not found! Please enter a valid command" << std::endl;
      break;
    }

    entry.clear();
  }
  
  AvlTree* avlTree = new AvlTree();
  avlTree->insert(5, avlTree->getRoot(), true);
  //std::cout << (((avlTree->getRoot())->right)->key) << std::endl;
  avlTree->print(avlTree->getRoot());
  delete avlTree;
  
  return 0;
}
