//  File: menu.cc

#include "menu.h"


menu::menu(int size)
{
  myMenu.reserve(size);
}


void menu::insert(std::string itemStr)
{
  myMenu.push_back(itemStr);
}

int menu::select(std::string& selection)
{
  int i;

  for(i=0; i < myMenu.size(); i++)
    {
      std::cout << i  << ". " << myMenu[i] << std::endl;
    }
  std::cout << "Make a Selection " << std::endl;
  std::cin >> i;
  selection=myMenu[i];
  return(i);
}
