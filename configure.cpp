#include "configure.h"

void Configure::initialize(std::istream& configFile){
	std::string line;
	while(getline(configFile, line, '\n')){
		std::vector<std::string> inputs = split(line, '#');
		settings.insert(std::pair<std::string, std::string>(inputs.at(0), inputs.at(1)));
	}
	return;
}

std::string Configure::processInput(std::string input){
	std::map<std::string, std::string>::iterator it = settings.find(input);
	if(it != settings.end()){
		return it->second;
	} else {
		std::string dummy = "";
		return dummy;
	}
}

std::vector<std::string> split(std::string input, char delim){
	std::stringstream ss;
	ss.str(input);
	std::vector<std::string> result;
	std::string segment;
	while(std::getline(ss, segment, delim)){
		result.push_back(segment);
	}
	_(std::cout << "Segment 1: " << result.at(0) << "\n";)
	_(std::cout << "Segment 2: " << result.at(1) << "\n";)
	return result;
}
