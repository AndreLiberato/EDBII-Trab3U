#include <unordered_map>
#include <string>

class Command {
  public:
    enum commands {
      insert,
      remove,
      search,
      exit
    };

  private:
    std::unordered_map<std::string, commands> matchCommand = {
      {"i", commands::insert},
      {"r", commands::remove},
<<<<<<< HEAD
      {"list", commands::list},
      {"select", commands::select},
    };
  
  public:

    Command();

    int get_command(std::string command);
};
