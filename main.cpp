#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "define.h"
#include "configure.h"

using namespace std;

int main(){
	//Read in configuration file data
	ifstream fileData;
	fileData.open("configure.txt");
	Configure settings;
	settings.initialize(fileData);
	fileData.close();

	while(1){
		string input;
		//If there is network or command line input
		if(getline(cin, input, '\n')){
			_(cout << "Input detected: " << input << "\n";)
			string result = settings.processInput(input);
			if(result != ""){
				system(result.c_str());
			} else {
				cout << "No option detected.\n";
			}
		}
	}
	return 0;
}