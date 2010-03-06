  
#include <gtkmm.h>


class rOpColumns : public Gtk::TreeModelColumnRecord
  {
  public:

    rOpColumns()
    { add(name_col_text); }

    Gtk::TreeModelColumn<Glib::ustring> name_col_text;

  };

class bmColumns : public Gtk::TreeModelColumnRecord
  {
  public:

    bmColumns()
    { add(name_col_text); }

    Gtk::TreeModelColumn<Glib::ustring> name_col_text;

  };

class caColumns : public Gtk::TreeModelColumnRecord
  {
  public:

    caColumns()
    { add(name_col_text); }

    Gtk::TreeModelColumn<Glib::ustring> name_col_text;

  };


class secColumns : public Gtk::TreeModelColumnRecord
  {
  public:

    secColumns()
    { add(abbr_col_text); add(full_col_text);}

    Gtk::TreeModelColumn<Glib::ustring> abbr_col_text;
    Gtk::TreeModelColumn<Glib::ustring> full_col_text;
  };




