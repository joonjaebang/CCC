#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "define.h"

class Configure{
private:
	std::map<std::string, std::string> settings;
public:
	Configure () {}
	void initialize(std::istream& configFile);
	std::string processInput(std::string input);
	~Configure () {}
	void getline(std::istream configFile, std::__cxx11::string line, char arg3);
};

std::vector<std::string> split(std::string input, char delim);
