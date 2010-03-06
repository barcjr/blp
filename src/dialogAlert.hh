// generated 2006/3/16 16:47:22 MST by bda@localhost.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to dialogAlert.hh_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _DIALOGALERT_HH
#  include "dialogAlert_glade.hh"
#  define _DIALOGALERT_HH
class dialogAlert : public dialogAlert_glade
{  
  
public:
  void alert(std::string message); 
  dialogAlert(void);
};
#endif
