// data access code

#include "blp.h"
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <fstream>

#define MAXHOSTNAME 30

//************************
// this is the constructor


dataAccessMan::dataAccessMan(std::string dataBaseHost, std::string dataBaseName, 
			     std::string dataBaseUser, std::string dataBasePasswd, progLog *logObj)
{
  dataHost=dataBaseHost;
  dataBase=dataBaseName;
  dataUser=dataBaseUser;
  dataPasswd=dataBasePasswd;
  logger=logObj;
  char tmpHostName[MAXHOSTNAME];

  logger->logData("DAM constructor start", LOGMESSAGES);

  mysql_init(&loggingDB);
  if(!(mysql_real_connect(&loggingDB, dataHost.c_str(), dataUser.c_str(), 
			  dataPasswd.c_str(),dataBase.c_str(),0, NULL, 0))) 	
    {
      std::cerr << (mysql_error(&loggingDB));
      exit(1);
    }
  if(gethostname(tmpHostName, MAXHOSTNAME))
    {
      logger->logData("Failed to get the host name", LOGERRORS);
      std::cerr << "Failed to get the host name" << std::endl;
      exit(1);
    }
  hostName=tmpHostName;
  logger->logData("Data Access Manager Initialized", LOGMESSAGES);

}



//****************************
// member fillOperatorList initilizes a menu with all of the operator names


bool dataAccessMan::getOperatorList(std::vector<std::string>& list)
{
  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;
  std::string operatorText;
  int i, numRows;

  logger->logData("Filling Operator List", LOGMESSAGES);

  std::string queryText;
  queryText="Select Name, CallSign from Operator";
  logger->logData("Operator Query->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error duringOperator query");
      return(0);
    }
  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  numRows=mysql_num_rows(res);
  for(i=0; i < numRows; i++)
    {
      row=mysql_fetch_row(res); 		/* Get a row from the results */
      operatorText= row[0];
      operatorText.append(" (");
      operatorText.append(row[1]);
      operatorText.append(")");
      list.push_back(operatorText);
     }
  mysql_free_result(res);
  logger->logData("Operator List Complete", LOGMESSAGES);
  return 1;
}


//*******************************
// member fillBandMode fills a menu list with the available bandModes



bool dataAccessMan::getBandModeList(std::vector<std::string>& list)
{
  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;
  std::string bandModeText;
  int i, numRows;

  logger->logData("Filling BandMode List", LOGMESSAGES);

  std::string queryText;
  queryText="Select Title from BandMode";
  logger->logData("BandModeList Query->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during BandModeList query");
      return(0);
    }
  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  numRows=mysql_num_rows(res);
  for(i=0; i < numRows; i++)
    {
      row=mysql_fetch_row(res); 		/* Get a row from the results */
      bandModeText= row[0];
      list.push_back(bandModeText);
    }
  mysql_free_result(res);
  logger->logData("BandMode List Complete", LOGMESSAGES);
  return 1;
}



//*******************************************************
// member getPartialCalls is passed a partial call and fills a menu withall the calls
//                         in the database that match the partial call



bool dataAccessMan::getPartialCalls(std::vector<std::string>& list, std::string partialCall)
{
  MYSQL_RES *subRes; 		// To be used to fetch information into 
  MYSQL_RES *res;
  MYSQL_ROW row;
  std::string partialCallText;
  int i, numRows;

  std::string bandModeID;
  std::string stationID;


  logger->logData("Filling Partial Call List", LOGMESSAGES);

  std::string queryText;

  // Get bandMode ID
  queryText = "SELECT BandModeID FROM BandMode where CurrentUser=\"" + hostName + "\"";
     
  logger->logData("DUPE Query->" + queryText + "<-", LOGSQL);

  mysql_real_query(&loggingDB, queryText.c_str(), queryText.length());
  res = mysql_store_result(&loggingDB);

  row = mysql_fetch_row(res);
  bandModeID = row[0];
  mysql_free_result(res);


  queryText="Select StationCall, StationID from Station where (StationCall) like \'" + partialCall + "%\'";
  logger->logData("Partial Call List Query->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during Partial Call List query");
      return(0);
    }
  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  numRows=mysql_num_rows(res);
  for(i=0; i < numRows; i++)
    {
      row=mysql_fetch_row(res); 		/* Get a row from the results */
      partialCallText= row[0];
      stationID = row[1];


      
      queryText="SELECT * FROM Contact where BandModeID=\"" + bandModeID + "\" and StationID=\"" + stationID + "\"";
      logger->logData("DUPE Query->" + queryText + "<-", LOGSQL);
      mysql_real_query(&loggingDB, queryText.c_str(), queryText.length());
      subRes = mysql_store_result(&loggingDB);
      if( mysql_num_rows(subRes) != 0 ) {
	partialCallText.append(" - DUPE!");
      }

      mysql_free_result(subRes);

      list.push_back(partialCallText);
    }
  mysql_free_result(res);
  logger->logData("Partial Call List Complete", LOGMESSAGES);
  return 1;
}





bool dataAccessMan::getPartialSections(std::vector<std::string>& list, std::string partialSection)
{
  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;
  std::string partialSectionText;
  int i, numRows;

  logger->logData("Filling Partial Section List", LOGMESSAGES);

  std::string queryText;
  queryText="Select Abbr, FullName from Section where (Abbr) like \'" + partialSection + "%\' OR (FullName) like \'" + partialSection + "%\'";
  logger->logData("Partial Section List Query->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during Partial Section List query");
      return(0);
    }
  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  numRows=mysql_num_rows(res);
  for(i=0; i < numRows; i++)
    {
      row=mysql_fetch_row(res); 		/* Get a row from the results */
      partialSectionText= row[0];
      partialSectionText.append(" ");
      partialSectionText.append(row[1]);
      list.push_back(partialSectionText);
    }
  mysql_free_result(res);
  logger->logData("Partial Section List Complete", LOGMESSAGES);
  return 1;
}







//*****************************************
//   menber getStation is passed a string that contains the call of the station
//                     to be pulled from the database and returned 


int  dataAccessMan::getStation(std::string call,  radioStation *thisStation)
{
  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;

  logger->logData("getStation entered", LOGMESSAGES);

  std::string queryText;
  queryText="Select t1.StationCall, t2.Abbr, t1.ContestClass from Station as t1 inner join Section as t2 where t1.SectionID = t2.SectionID and t1.StationCall=\"" +  call + "\"";
  logger->logData("Station Query->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during station query");
      return(-1);
    }
  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  row=mysql_fetch_row(res); 		/* Get a row from the results */
  if(mysql_num_rows( res) == 0)
    {
      logger->logData("No Station Found", LOGMESSAGES);	
      mysql_free_result(res);
      return 0;
    }

  thisStation->callSign=row[0];
  thisStation->section=row[1];
  thisStation->conClass=row[2];
  logger->logData("Station found", LOGMESSAGES);
  mysql_free_result(res);
  return 1;
}



bool dataAccessMan::reserveBandMode(bandMode& thisBandMode)
{
  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;
  std::string userName;

  logger->logData("Reserving BandMode", LOGMESSAGES);

  std::string queryText;
  queryText="Select * from BandMode where Title=\"" +  thisBandMode.title + "\"";
  logger->logData("bandMode Query->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during bandMode query");
      return(0);
    }
  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  row=mysql_fetch_row(res); 		/* Get a row from the results */
  if(mysql_num_rows( res) == 0)
    {
      logger->logData("No BandMode Found", LOGMESSAGES);	
      mysql_free_result(res);
      return 0;
    }

  thisBandMode.title=row[5];
  thisBandMode.upperLimit= atof(row[4]);
  thisBandMode.lowerLimit= atof(row[3]);
  thisBandMode.mode=row[2];
  thisBandMode.band=row[1];
  if(row[6] == '\0')
    {
      queryText="Update BandMode set CurrentUser=\"" + hostName + "\" where Title=\"" + thisBandMode.title + "\" limit 1";
      logger->logData("bandModeUpdate->" + queryText + "<-", LOGSQL);

      if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
	{
	  logDbError("Error during bandMode Update");
	  mysql_free_result(res);
	  return(0);
	}
      mysql_free_result(res);
      logger->logData("BandMode is reserved", LOGMESSAGES);
      return(1);
    }
  logger->logData("BandMode is NOT resreved", LOGMESSAGES);
  mysql_free_result(res);
  return(0);
      
}


	
void dataAccessMan::releaseBandMode(void)
{
  std::string queryText;
  logger->logData("Release BandMode start", LOGMESSAGES);
  queryText="Update BandMode set CurrentUser=NULL where CurrentUser=\"" + hostName + "\"" ;
  logger->logData("bandModeUpdate->" + queryText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during bandMode Update");
    }
  logger->logData("BandMode done", LOGMESSAGES);
	
}





int dataAccessMan::saveQSO(contact *thisContact)
{
  std::string  	insertText;
  std::string	stationID;
  std::string	radioOP;
  std::string	logOP;
  std::string	bandModeID;
  std::string	frequency;
  std::ostringstream  outs;
  std::string::size_type pos;
  std::ofstream dumpFile;
  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;
  std::string queryText;

  queryText="Select StationID from Station where StationCall=\"" + thisContact->curStation.callSign + "\"";
  logger->logData("Initial QSO Station Query->" + queryText + "<-", LOGSQL);
  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during Initial QSO Station query");
      return(0);
    }

  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  if(mysql_num_rows(res) == 0)
    {
      mysql_free_result(res);
      if(!addStation(&(thisContact->curStation))) {
	logDbError("Couldn't add station!");
	return (0);
      }
      queryText="Select StationID from Station where StationCall=\"" +  thisContact->curStation.callSign + "\"";
      logger->logData("Initial QSO Station Query->" + queryText + "<-", LOGSQL);

      if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
	{
	  logDbError("Error during Initial QSO Station query");
	  return(0);
	}
      res=mysql_store_result(&loggingDB);
    }

  row=mysql_fetch_row(res); 		/* Get a row from the results */
  stationID = row[0];
  mysql_free_result(res);

  //Get the OperatorID

  pos=thisContact->radioOperator.find(" (", 0);
  if(pos !=std::string::npos)
    thisContact->radioOperator=thisContact->radioOperator.substr(0, pos);
  queryText="Select OperatorID from Operator where Name=\"" + thisContact->radioOperator + "\"";
  logger->logData("Radio OperatorID Query->" + queryText + "<-", LOGSQL);
  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error duringOperatoID query");
      return(0);
    }

  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  if(mysql_num_rows(res) == 0)
    {
      logDbError("Radio Operator not found");
      return 0;
    }
  row=mysql_fetch_row(res);
  radioOP = row[0];
  mysql_free_result(res);

  // Get the logger ID


  pos=thisContact->loggingOperator.find(" (", 0);
  if(pos !=std::string::npos)
    thisContact->loggingOperator=thisContact->loggingOperator.substr(0, pos);

  queryText="Select OperatorID from Operator where Name=\"" +  thisContact->loggingOperator + "\"";
  logger->logData("Logging OperatorID Query->" + queryText + "<-", LOGSQL);
  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during Logging OperatoID query");
      return(0);
    }

  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  if(mysql_num_rows(res) == 0)
    {
      logDbError("Logging Operator not found");
      return 0;
    }
  row=mysql_fetch_row(res);
  logOP = row[0];
  mysql_free_result(res);

  // Get the bandMode ID

  queryText="Select BandModeID from BandMode where Title=\"" +  thisContact->currentBandMode->title + "\"";
  logger->logData("BandModeID Query->" + queryText + "<-", LOGSQL);
  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during BandModeID query");
      return(0);
    }

  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  if(mysql_num_rows(res) == 0)
    {
      logDbError("BandMode not found");
      return 0;
    }
  row=mysql_fetch_row(res);
  bandModeID = row[0];
  mysql_free_result(res);

  //Check for duplicates

 queryText="Select StationID, BandModeID from Contact where BandModeID=\""+ bandModeID + "\" and StationID= \""+ stationID + "\"";
  logger->logData("BandModeID Query->" + queryText + "<-", LOGSQL);
  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during Dupe Check query");
      return(0);
    }

  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  if(mysql_num_rows(res) != 0)
    {
      mysql_free_result(res);
      logDbError("Duplicate found");
      return -1;
    }

  mysql_free_result(res);




  // Set frequency
  outs << thisContact->currentFreq;
  frequency = outs.str();

    

  insertText="Insert into Contact (StationID, RadioOp, Logger, BandModeID, Frequency) values (" + 
    stationID + "," +
    radioOP + "," +
    logOP + "," +
    bandModeID + "," +
    frequency + ")" ;
  logger->logData("Insert Contact->" + insertText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, insertText.c_str(), insertText.length())))
    {
      logDbError("Error during Insert Contact");
    }
  logger->logData("Insert Contact done", LOGMESSAGES);

  dumpFile.open("contacts.txt", std::ios::out | std::ios::app);
  dumpFile << thisContact->curStation.callSign << "\t";
  dumpFile << thisContact->curStation.conClass << "\t";
  dumpFile << thisContact->curStation.section << "\t";
  dumpFile << thisContact->radioOperator << "\t";
  dumpFile << thisContact->loggingOperator << "\t";
  dumpFile << thisContact->currentBandMode->title << "\t" << frequency << "\n";
  dumpFile.close();
}


bool dataAccessMan::addStation(radioStation * thisStation)
{
  std::string insertText;	
  std::string sectionID;

  MYSQL_RES *res; 		// To be used to fetch information into 
  MYSQL_ROW row;
  std::string queryText;


  queryText="Select SectionID from Section where Abbr=\"" +  thisStation->section + "\"";
  logger->logData("SectionID Query->" + queryText + "<-", LOGSQL);
  if( (mysql_real_query(&loggingDB, queryText.c_str(), queryText.length())))
    {
      logDbError("Error during SectionID query");
      return(0);
    }

  res=mysql_store_result(&loggingDB); 	/* Download result from server */
  if(mysql_num_rows(res) == 0)
    {
      logDbError("Section not found");
      return 0;
    }
  row=mysql_fetch_row(res);
  sectionID = row[0];
  mysql_free_result(res);




  insertText="INSERT INTO Station(StationCall, SectionID, ContestClass) VALUES (\"" + 
    thisStation->callSign + "\", " +
    sectionID + ", \"" +
    thisStation->conClass + "\")" ;
  logger->logData("Insert Station->" + insertText + "<-", LOGSQL);

  if( (mysql_real_query(&loggingDB, insertText.c_str(), insertText.length())))
    {
      logDbError("Error during Insert Station");
      return 0;
    }
  logger->logData("Insert Station done", LOGMESSAGES);
  return 1;

}



void dataAccessMan::logDbError(std::string errorMessage)
{
  std::string mysqlMessage;

  mysqlMessage=mysql_error(&loggingDB);
  logger->logData(errorMessage + mysqlMessage + "<eom>", LOGERRORS);
}
