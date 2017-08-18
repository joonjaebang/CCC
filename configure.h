#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <vector>
#include "define.h"

struct config_Entry{
	std::string command;
	int auth_Code;
	std::string program;
};

class Configure{
private:
	std::vector<config_Entry*> settings;
public:
	Configure () {}
	void initialize(std::istream& configFile);
	void printSettings(std::vector<config_Entry*> settings);
	std::vector<config_Entry*> return_Settings();
	~Configure () {}
};

std::vector<std::string> split(std::string input, char delim);