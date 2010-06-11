#ifndef _BLP_H
#  define _BLP_H


#include "parapin.h"

#define USE_OLD_FUNCTIONS
#include <mysql/mysql.h>
#include <hamlib/rig.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <boost/bind.hpp>
#include <gtkmm/dialog.h>
#include <pthread.h>

//defines for log levels
#define LOGERRORS 0x01
#define LOGDATA	0x02
#define LOGMESSAGES 0x04
#define LOGSQL 0x08
#define LOGALL 0xff


struct bandMode  {
  std::string	title;
  std::string	mode;
  std::string	band;
  double	lowerLimit;
  double	upperLimit;
  bandMode(void);
};


class radioStation {

 public:
  std::string	callSign;
  std::string	section;
  std::string	conClass;
  radioStation(void);
  radioStation(std::string call, std::string section, std::string conClass);
};


class progLog  {
  std::ofstream logFile;
  int currentLogLevel;
 public:
  progLog(std::string logFileName, int logLevel);
  void setLogLevel(int level);
  void logData(std::string data, int logFlag);
  ~progLog(void);
};

struct  contact 
{
  radioStation	curStation;
  std::string	radioOperator;
  std::string	loggingOperator;
  double	currentFreq;
  bandMode *currentBandMode;
};




class dataAccessMan  {
  std::string requestedOperator;
  int bandModeListCount;
  std::string	dataHost;
  std::string	dataBase;
  std::string	dataUser;
  std::string	dataPasswd;
  MYSQL loggingDB;
  progLog		*logger;
  void logDbError(std::string errorMessage);
  std::string  hostName;

 public:
  dataAccessMan(std::string dataBaseHost, std::string dataBaseName, std::string dataBaseUser, std::string dataBasePasswd, progLog *logObj);
  bool  getOperatorList(std::vector<std::string>& list);
  bool getBandModeList(std::vector<std::string>& list);
  bool getPartialCalls(std::vector<std::string>& list, std::string partialCall);
  bool getPartialSections(std::vector<std::string>&, std::string partialSection);
  int getStation(std::string call, radioStation *thisStation);
  int saveQSO(contact *thisContact);
  bool reserveBandMode(bandMode& thisBandMode);
  void releaseBandMode(void);	
  bool addStation(radioStation *thisStation);

};


class contactManager  {
  contact myContact;
  dataAccessMan *myDam;
  std::ostringstream  outs;
  unsigned char state;
  void updateStatus(void);
  bandMode myBandMode;
  std::string band_str;
  std::string mode_str;
  bool checkFreq;
 public:

  contactManager( dataAccessMan *dam, bool _checkFreq );
  bool partialCallInput(std::vector<std::string>& list, std::string);
  bool partialSectionInput(std::vector<std::string>& list, std::string partialCall);
  void radioOperatorSelected(std::string newOperator);
  void loggerSelected(std::string newLogger);
  void setFrequency(double newFreq);
  bool is_inBand();
  void bandModeSelected(std::string newBandMode);
  void switchBPF();
  void callSelected(std::string newCall);
  void classSelected(std::string newClass);
  void sectionSelected(std::string newSection);
  bool saveCmd(void);
  void clearContact(void);
};

bool oob_poll(contactManager* theMan, Gtk::Dialog* theDialog);

// Hamlib poll calls
bool hamlib_poll(contactManager* theMan);
void *hamlib_poll_thread(void *myPassedRig);

#endif
