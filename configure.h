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
};

std::vector<std::string> split(std::string input, char delim);
