//  progLog.cc program logging class


#include	<iostream>
#include	<fstream>
#include	"blp.h"
#include	<time.h>

progLog::progLog(std::string logFileName, int logLevel)
{
  logFile.open(logFileName.c_str(), std::ios::out | std::ios::app);
  if(logFile.fail())
    {
      std::cerr << "Unable to open the logging file " << logFile << std::endl;
      exit(-1);
    }
  currentLogLevel=logLevel;
}

progLog::~progLog(void)
{
	logFile.close();
}




void progLog::setLogLevel(int level)
{
  currentLogLevel=level;
}




void progLog::logData(std::string data, int logFlag)
{
  time_t  currentTime;
  char timeStr[30];
  std::string  timeBuffer;

  timeBuffer[0]='\0';
  currentTime=time(&currentTime);
  if(ctime_r(&currentTime, timeStr) == NULL)
	  timeBuffer[0]='\0';
  timeBuffer=timeStr;
  timeBuffer.erase(timeBuffer.length()-1);
  if( logFlag & currentLogLevel)
    {
      logFile << timeBuffer << " " << data << std::endl;
      logFile.flush();
    }

}
