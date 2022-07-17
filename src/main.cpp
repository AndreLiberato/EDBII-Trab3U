#include "Util.hpp"
#include "Command.hpp"
#include "AvlTree.hpp"

using namespace avlt;
using std::cout;
using std::endl;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  std::string entry;
  std::string command;
  std::string value;
  Command command_sys;

  AvlTree* avlTree = new AvlTree();

  bool h = true;

  /* avlTree->insert(5, avlTree->getRoot(), &h);

  h = true;
  avlTree->insert(-1, avlTree->getRoot(), &h);

  h = true;
  avlTree->insert(2, avlTree->getRoot(), &h);

  h = true;
  avlTree->insert(-2, avlTree->getRoot(), &h);

  h = true;
  avlTree->insert(7, avlTree->getRoot(), &h);

  h = true;
  avlTree->insert(-99999, avlTree->getRoot(), &h);
  
  avlTree->print(avlTree->getRoot()); */

  while (true)
  {
    std::cout << "avlt_cli> ";
    std::getline(std::cin, entry);

    command = split(entry).front();
    value = split(entry).back();

    switch (command_sys.get_command(command)) {
    case command_sys.insert:
      std::cout << "insert" << std::endl;
      h = true;
      avlTree->insert(stoi(value), avlTree->getRoot(), &h);
      avlTree->print(avlTree->getRoot());
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
    command.clear();
    value.clear();
  }

  delete avlTree;

  return 0;
}
