//these are the core routines for the logging program

#include <vector>

#include "logCore.h"

dataAccessMan::dataAccessMan(void) {


//initilize the bandModeList
	string entry;
	bandModeListCount=0;
	fetchBandMode(FIRST);
	do {
		bandModeList.push_back(
	}while( fetchBandMode(NEXT) != NULL ) 
