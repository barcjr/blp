//  List init code here


#include <windowBLP.hh>
#include "listInit.hh"


void initOperator()
{
  


  Glib::RefPtr<Gtk::ListStore> opRefListStore = Gtk::ListStore::create(operatorColumns);
  comboboxOperator->set_model(opRefListStore);
  comboboxLogger->set_model(opRefListStore);

  Gtk::TreeModel::Row row = *(opRefListStore->append());
  row[operatorColumns.name_col_text] = "Number 1";

  row = *(opRefListStore->append());
  row[operatorColumns.name_col_text] = "Number 2";

  row = *(opRefListStore->append());
  row[operatorColumns.name_col_text] = "Number 3";

  row = *(opRefListStore->append());
  row[operatorColumns.name_col_text] = "Number 4";


   comboboxOperator->append_column("Messages", operatorColumns.name_col_text);
