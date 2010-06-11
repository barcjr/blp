//  FILE contact.cc

#include <iostream>
#include <iomanip>
using namespace std;
#include "windowBLP.hh"
#include "blp.h"

#define HAVE_OPERATOR 	0x01
#define HAVE_LOGGER	0x02
#define HAVE_BAND	0x04
#define HAVE_CALL	0x08
#define HAVE_CLASS	0x10
#define HAVE_SECTION	0x20
#define HAVE_ALL	0x3f
#define READY_TO_LOG	0x07
#define CLEAR_QSO	0x07

extern windowBLP *windowBLP;


radioStation::radioStation(void)

{
  callSign.erase();
  section.erase();
  conClass.erase();
}


bandMode::bandMode(void)
{
  mode.erase();
  band.erase();
  lowerLimit=0.0;
  upperLimit=0.0;	
}



contactManager::contactManager(dataAccessMan *dam, bool _checkFreq)
{
  myDam=dam;
  myContact.curStation.callSign ="";
  myContact.curStation.section ="";	
  myContact.curStation.conClass="";
  myContact.radioOperator ="";
  myContact.loggingOperator ="";
  myContact.currentFreq=0.0;
  myContact.currentBandMode=&myBandMode;
  checkFreq = _checkFreq;
  state=0;

}

void contactManager::updateStatus(void)
{

  windowBLP->enableEntry();
  if(!is_inBand()) {
    cout << myContact.currentFreq << endl;
    cout << myBandMode.upperLimit << endl;
    cout << myBandMode.lowerLimit << endl;
    windowBLP->showStatus("Out of Band!");
    windowBLP->disableEntry();
    return;
  }
  std::string statusMessage;
  if((state & READY_TO_LOG) != READY_TO_LOG)
    windowBLP->disableEntry();

  if (!(state & HAVE_OPERATOR))
    {
      statusMessage="Radio Operator Needs to Login";
      windowBLP->showStatus(statusMessage);
      return;
    }

  if (!(state & HAVE_LOGGER))
    {
      statusMessage="Logging Operator Needs to Login";
      windowBLP->showStatus(statusMessage);
      return;
    }
  if (!(state & HAVE_BAND))
    {
      statusMessage="Select a Band for Operating";
      windowBLP->showStatus(statusMessage);
      return;
    }
  if (state == READY_TO_LOG)
    {
      statusMessage="Ready for logging";
      windowBLP->showStatus(statusMessage);
      return;
    }
  if(!(state & HAVE_CALL))
    statusMessage.append("Enter Call ");

  if(!(state & HAVE_CLASS))
    statusMessage.append("Enter his Class ");

  if(!(state & HAVE_SECTION))
    statusMessage.append("Enter his Section ");
	
  windowBLP->showStatus(statusMessage);
  return;
}
		


bool contactManager::partialCallInput(std::vector<std::string>& list, std::string partialCall)
{
  return (myDam->getPartialCalls(list,partialCall));
}


bool contactManager::partialSectionInput(std::vector<std::string>& list, std::string partialSection)
{
  return (myDam->getPartialSections(list,partialSection));
}


void contactManager::radioOperatorSelected(std::string newOperator)
{
  if(newOperator == "Logout")
    {
      state= state & (~HAVE_OPERATOR);
      myContact.radioOperator="";
    }
  else
    {
      myContact.radioOperator=newOperator;
      state=state | HAVE_OPERATOR;
    }
  updateStatus();
  return;
}

void contactManager::loggerSelected(std::string newLogger)
{
  if(newLogger == "Logout")
    {
      state=state & (~HAVE_LOGGER);
      myContact.loggingOperator="";
    }
  else
    {
      myContact.loggingOperator=newLogger;
      state=state | HAVE_LOGGER;
    }
  updateStatus();
  return;

}

void contactManager::setFrequency(double newFreq)
{
  if(myContact.currentFreq == newFreq)
    return;
  myContact.currentFreq = newFreq;
  windowBLP->set_freqs(myBandMode.lowerLimit, myBandMode.upperLimit,
		       myContact.currentFreq);
  updateStatus();
}

bool contactManager::is_inBand()
{
  if( !checkFreq || myBandMode.lowerLimit < myContact.currentFreq && myBandMode.upperLimit > myContact.currentFreq) 
    return true;
  else
    return false;
}

void contactManager::bandModeSelected(std::string newBandMode)
{

  myDam->releaseBandMode();
  if(newBandMode == "NONE") 
    {
      state= state & (~HAVE_BAND);
      updateStatus();
      return;
    }
  myBandMode.title=newBandMode;
  if(!myDam->reserveBandMode(myBandMode))
    {
      windowBLP->alert("Requested Band is NOT Available");
      state=state & ~HAVE_BAND;
    }

  else
    {
      state= state | HAVE_BAND;
    }

  clear_pin(LP_DATA_PINS);
  if( myBandMode.band == "160m" ) {
    set_pin(LP_PIN02);
  } else if ( myBandMode.band == "80m" ) {
    set_pin(LP_PIN03);
  } else if ( myBandMode.band == "40m" ) {
    set_pin(LP_PIN04);
  } else if ( myBandMode.band == "20m" ) {
    set_pin(LP_PIN05);
  } else if ( myBandMode.band == "15m" ) {
    set_pin(LP_PIN06);
  } else if ( myBandMode.band == "10m" ) {
    set_pin(LP_PIN07);
  }

  updateStatus();
  return;
}


void contactManager::callSelected(std::string newCall)
{
  int i;
  if( (state & READY_TO_LOG) != READY_TO_LOG)
    return;

  if(myDam->getStation(newCall, &myContact.curStation))
    {
      windowBLP->fillClass(myContact.curStation.conClass);
      windowBLP->fillSection(myContact.curStation.section);
      state = state | HAVE_CALL | HAVE_CLASS | HAVE_SECTION;
    }
  else
    {
      if(newCall.length() < 3)
	state = state & ~HAVE_CALL; 
      else  
	state = state | HAVE_CALL;
      
      myContact.curStation.callSign=newCall;
    }

  updateStatus();
  return;
}

void contactManager::classSelected(std::string newClass)
{
  if( (state & READY_TO_LOG) != READY_TO_LOG)
    return;

  if(newClass.length() < 2)
    state = state & ~HAVE_CLASS;
  else
    state = state | HAVE_CLASS;

  myContact.curStation.conClass=newClass;
  updateStatus();
  return;
}




void contactManager::sectionSelected(std::string newSection)
{
  if( (state & READY_TO_LOG) != READY_TO_LOG)
    return;
  myContact.curStation.section=newSection;
  if(newSection.empty())
    state = state & ~HAVE_SECTION;
  else
    state = state | HAVE_SECTION;
  updateStatus();
  return;

}
	
bool contactManager::saveCmd(void)
{
  std::string alertMessage;
  int retValue;


  if( state != HAVE_ALL)
    {
      alertMessage="Missing Data\n";
      if( !(state & HAVE_CALL))
	alertMessage.append("Need CALL\n");
      if(!(state & HAVE_CLASS))
	alertMessage.append("Need CLASS\n");
      if(!(state & HAVE_SECTION))
	alertMessage.append("Need SECTION\n");
      windowBLP->alert(alertMessage);
      return 0;
    }

  if((retValue=myDam->saveQSO(&myContact))== 0)
    {
      windowBLP->alert("Unable to save the QSO");
      return 0;
    }

  if(retValue == -1)
    {
      windowBLP->alert("Duplicate QSO, not saved");
      return 0;
    }


  clearContact();
  return 1;
}



void contactManager::clearContact(void)
{
  myContact.curStation.callSign ="";
  myContact.curStation.section ="";	
  myContact.curStation.conClass="";
  state=CLEAR_QSO;
  updateStatus();
  //  state = state & (~HAVE_CALL);
  //  std::cout << "State1=" << state << std::endl;
  //  state = state & (~HAVE_CLASS);
  //  std::cout << "State2=" << state << std::endl;
  //  state = state & (~HAVE_SECTION);
  //  std::cout << "State3=" << state << std::endl;
}
