// generated 2006/3/8 16:31:49 MST by bda@localhost.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to windowBLP.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "windowBLP.hh"
#include "dialogAlert.hh"
#include <iostream>
#include <string>
#include "windowBLP_glade.hh"
#include "listInit.hh"

#include <vector>

extern dialogAlert *dialogAlert;
using namespace std;

windowBLP::windowBLP(contactManager *thisMan)
{
  myMan=thisMan;

  vector<Gtk::Widget *> top_focus_chain;
  vector<Gtk::Widget *> focus_chain;
  Gtk::Container* vboxAll = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(get_children())[0]);
  Gtk::Container* tableContact = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(vboxAll->get_children())[2]);
  top_focus_chain.push_back(tableContact);
  vboxAll->set_focus_chain(top_focus_chain);
  focus_chain.push_back(entryCall);
  focus_chain.push_back(entryConClass);
  focus_chain.push_back(entrySection);
  tableContact->set_focus_chain(focus_chain);
  disableEntry();
  set_focus(*entryCall);
}

void windowBLP::on_new_operator_activate()
{  
  std::string command = "gnome-www-browser ";
  system(command.append(hostname).append("/adduser.php &").c_str());
}

void windowBLP::on_quit_activate()
{  
  Gtk::Main::quit();
}

void windowBLP::on_qso_activate()
{
}

void windowBLP::on_operator_name_activate()
{  
}

void windowBLP::on_station_activate()
{  
}

void windowBLP::on_history_activate()
{ 
  std::string command = "gnome-www-browser ";
  system(command.append(hostname).append("/history.php &").c_str());
}

void windowBLP::on_score_activate()
{
  std::string command = "gnome-www-browser ";
  system(command.append(hostname).append("/score.php &").c_str());
}

void windowBLP::on_reports_activate()
{  
}

void windowBLP::on_about1_activate()
{  
}

void windowBLP::on_help_activate()
{  
}

void windowBLP::on_comboboxLogger_changed()
{
  rOpColumns radioOpColumns;

  Gtk::TreeModel::Row row= *comboboxLogger->get_active();
  Glib::ustring name = row[radioOpColumns.name_col_text];
  myMan->loggerSelected(name);
  
}

void windowBLP::on_comboboxBandMode_changed()
{  
  bmColumns bandModeColumns;

  Gtk::TreeModel::Row row= *comboboxBandMode->get_active();
  Glib::ustring name = row[bandModeColumns.name_col_text];
  myMan->bandModeSelected(name);

}

void windowBLP::on_comboboxOperator_changed()
{  
  rOpColumns radioOpColumns;

  Gtk::TreeModel::Row row= *comboboxOperator->get_active();
  Glib::ustring name = row[radioOpColumns.name_col_text];
  myMan->radioOperatorSelected(name);
}

void windowBLP::on_entryCall_changed()
{  
  caColumns callColumns;
  std::vector<std::string> caList;
  int i;
  std::string text;

  text=entryCall->get_text();
  std::transform(text.begin(), text.end(), text.begin(), (int(*)(int))std::toupper);
  entryCall->set_text(text);

  Glib::RefPtr<Gtk::ListStore> callRefListStore = Gtk::ListStore::create(callColumns);
  treeviewCalls->set_model(callRefListStore);

  treeviewCalls->remove_all_columns();

  if (myMan->partialCallInput(caList,text))
    {
      for(i=0; i<caList.size(); i++)
	{
	  Gtk::TreeModel::Row row = *(callRefListStore->append());
	  row[callColumns.name_col_text] = caList.at(i);
	}
      treeviewCalls->append_column("", callColumns.name_col_text);
    }
}

bool windowBLP::on_entryCall_focus_out_event(GdkEventFocus *ev)
{
  std::string text;
  text=entryCall->get_text();
  myMan->callSelected(text);
  return 0;
}

bool windowBLP::on_entryConClass_focus_out_event(GdkEventFocus *ev)
{  
  std::string text;
  text=entryConClass->get_text();
  myMan->classSelected(text);
  return 0;
}

void windowBLP::on_entrySection_changed()
{  
  secColumns sectionColumns;
  std::vector<std::string> secList;
  int i;
  std::string text;

  text=entrySection->get_text();
  std::transform(text.begin(), text.end(), text.begin(), (int(*)(int))std::toupper);
  entrySection->set_text(text);
  if(text.length() == 0)  return;


  Glib::RefPtr<Gtk::ListStore> sectionRefListStore = Gtk::ListStore::create(sectionColumns);
  treeviewSections->set_model(sectionRefListStore);

  treeviewSections->remove_all_columns();

  if (myMan->partialSectionInput(secList,text))
    {
      for(i=0; i<secList.size(); i++)
	{
	  Gtk::TreeModel::Row row = *(sectionRefListStore->append());
	  row[sectionColumns.abbr_col_text] = secList.at(i);
	}
      treeviewSections->append_column("", sectionColumns.abbr_col_text);
    }
}

bool windowBLP::on_entrySection_focus_out_event(GdkEventFocus *ev)
{  
  std::string text;
  text=entrySection->get_text();
  myMan->sectionSelected(text);
  return 0;
}

void windowBLP::on_treeviewCalls_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column)
{ 
  caColumns callColumns; 
  Glib::RefPtr<Gtk::TreeSelection> callRefTreeSelection = treeviewCalls->get_selection();
  Gtk::TreeModel::Row row= *callRefTreeSelection->get_selected();
  Glib::ustring name = row[callColumns.name_col_text];
  entryCall->set_text(name);
  myMan->callSelected(name);

}

void windowBLP::on_treeviewSections_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column)
{  
  int pos;
  secColumns sectionColumns; 
  Glib::RefPtr<Gtk::TreeSelection> sectionRefTreeSelection = treeviewSections->get_selection();
  Gtk::TreeModel::Row row= *sectionRefTreeSelection->get_selected();
  Glib::ustring name = row[sectionColumns.abbr_col_text];
  pos=name.find(" ");
  name=name.substr(0,pos);
  entrySection->set_text(name);
  myMan->sectionSelected(name);

}

void windowBLP::on_ClearQSO()
{  
  myMan->clearContact();
  entryCall->set_text("");
  entrySection->set_text("");
  entryConClass->set_text("");
  treeviewCalls->remove_all_columns();
  treeviewSections->remove_all_columns();
  set_focus(*entryCall);
}

void windowBLP::on_SaveQSO()
{
  Gtk::Container* vboxAll = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(get_children())[0]);
  Gtk::Container* tableContact = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(vboxAll->get_children())[2]);
  set_focus(*entrySection);
  Gtk::Main::iteration();
  set_focus(*entryCall);
  Gtk::Main::iteration();
  if(myMan->saveCmd())
    {
      on_ClearQSO();
    }
}


void windowBLP::alert(std::string message)
{
  dialogAlert->alert(message);
  return;
}


void windowBLP::showStatus(std::string message)
{
  statusbarBLP->pop(0);
  std::stringstream msg;
  msg << message;
  msg.precision(5);
  msg << " ( " << m_lower / 10E5 << ", " << m_upper / 10E5 << " ) - " << m_current / 10E5;
  statusbarBLP->push(msg.str(), 0);
  return;
}

void windowBLP::set_freqs(double lower, double upper, double current)
{
  m_lower = lower;
  m_upper = upper;
  m_current = current;
  return;
}


void windowBLP::fillClass(std::string message)
{
  entryConClass->set_text(message);
  return;
}


void windowBLP::fillSection(std::string message)
{
  entrySection->set_text(message);
  return;
}


void windowBLP::fillCall(std::string message)
{
  return;
}



void windowBLP::disableEntry()
{
  Gtk::Container* vboxAll = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(get_children())[0]);
  Gtk::Container* tableContact = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(vboxAll->get_children())[2]);
  tableContact->set_sensitive(false);
}

void windowBLP::enableEntry()
{
  Gtk::Container* vboxAll = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(get_children())[0]);
  Gtk::Container* tableContact = dynamic_cast<Gtk::Container*>(static_cast< vector<Gtk::Widget *> >(vboxAll->get_children())[2]);
  tableContact->set_sensitive(true);
}
