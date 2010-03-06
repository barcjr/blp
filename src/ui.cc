// FILE ui.cc

#include "windowBLP.hh"


#include <string>
#include "blp.h"

extern std::string testCall;
extern std::string testSection;
extern std::string testClass;



uiDisplay::uiDisplay(std::string message)
{
  windowBLP->statusbarBLP->push("Initializing",0);    //this makes it so update status can do a pop
  std::cout << "UI Started with " <<  message << std::endl;
}



void uiDisplay::alert(std::string message)
{
  std::cout << "ALERT " << message << std::endl;
  return;
}

void uiDisplay::showStatus(std::string message)
{
  windowBLP->statusbarBLP->pop(0);
  windowBLP->statusbarBLP->push(message, 0);
  return;
}



void uiDisplay::fillClass(std::string message)
{
  std::cout << "Class now set to " << message << std::endl;
  testClass = message;
  return;
}


void uiDisplay::fillSection(std::string message)
{
  std::cout << "Section now set to " << message << std::endl;
  testSection = message;
  return;
}


void uiDisplay::fillCall(std::string message)
{
  std::cout << "Call now set to " << message << std::endl;
  testCall = message;
  return;
}


void uiDisplay::disableEntry()
{
  Gtk::Container* vboxAll = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(get_children())[0]);
  Gtk::Container* tableContact = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(vboxAll->get_children())[2]);
  tableContact->set_sensitive(false);
}

void uiDisplay::enableEntry()
{
  Gtk::Container* vboxAll = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(get_children())[0]);
  Gtk::Container* tableContact = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(vboxAll->get_children())[2]);
  tableContact->set_sensitive(true);
}
