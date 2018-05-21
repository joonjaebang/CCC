#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "define.h"
#include "configure.h"
#include "c3server.h"

using namespace std;

int main(){
	Server server;
	
	//Read in configuration file data
	ifstream fileData;
	fileData.open("configure.txt");
//	server.configure_settings(fileData);
	fileData.close();

	server.initialize(1337, true);
	
	return 0;
}
