#include "configure.h"

void Configure::initialize(std::istream& configFile){
	std::string line;
	while(getline(configFile, line, '\n')){
		std::vector<std::string> inputs = split(line, '#');
		config_Entry* entry = new config_Entry;
		entry->command = inputs.at(0);
		entry->auth_Code = std::stoi(inputs.at(1));
		entry->program = inputs.at(2);
		settings.push_back(entry);
	}
	_(printSettings(settings);)
	return;
}

std::vector<std::string> split(std::string input, char delim){
	std::stringstream ss;
	ss.str(input);
	std::vector<std::string> result;
	std::string segment;
	while(std::getline(ss, segment, delim)){
		result.push_back(segment);
	}
	return result;
}

void Configure::printSettings(std::vector<config_Entry*> settings){
	for(auto it=settings.begin(); it<settings.end(); ++it){
		std::cout << (*it)->command << " : " << (*it)->auth_Code << " : " << (*it)->program << "\n";
	}
	return;
}

std::vector< config_Entry* > Configure::return_Settings()
{
	return settings;
}

