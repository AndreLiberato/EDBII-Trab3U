#include <unordered_map>
#include <string>

class Command {
  public:
    enum commands {
      insert,
      remove,
      list,
      select,
      search,
      exit
    };

  private:
    std::unordered_map<std::string, commands> matchCommand = {
      {"i", commands::insert},
      {"remove", commands::remove},
      {"list", commands::list},
      {"select", commands::select},
      {"s", commands::search},
      {"exit", commands::exit}
    };
  
  public:

    Command();

    int get_command(std::string command);
};
