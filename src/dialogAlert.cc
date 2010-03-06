// generated 2006/3/16 16:47:22 MST by bda@localhost.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to dialogAlert.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "dialogAlert.hh"

extern dialogAlert *dialogAlert;

dialogAlert::dialogAlert(void)
{
  hide();
  return;
}



void dialogAlert::alert(std::string message)
{
  labelAlertText->set_text(message);
  run();
  hide();
}
