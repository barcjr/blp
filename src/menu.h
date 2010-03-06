//  File: menu.h

#include <iostream>
#include <vector>
#include <string>

class menu {
  std::vector<std::string> myMenu;

 public:
  menu(int size);
  void insert(std::string itemStr);
  int select(std::string& selection);

};
