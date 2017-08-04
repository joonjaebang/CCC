#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "define.h"
#include "configure.h"
#include "c3server.h"

using namespace std;

int main(){
	C3Server c3server;
	
	//Read in configuration file data
	ifstream fileData;
	fileData.open("configure.txt");
	c3server.settings.initialize(fileData);
	fileData.close();

	c3server.initialize(1337);
	
	return 0;
}