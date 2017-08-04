#include "c3server.h"

void C3Server::handle_connection(int sockfd){
	char buffer[256];
	while(recv(sockfd, buffer, 255, 0) > 0){
		int auth_code;
		std::stringstream ss;
		std::string command, auth_string;
		
		ss << buffer;
		std::getline(ss, command, '#');
		std::getline(ss, auth_string, '#');
		auth_code = std::atoi(auth_string.c_str());
		bzero(buffer, 256);
	}
	return;
}

void C3Server::configure_settings(std::ifstream & configFile){
	settings.initialize(configFile);
	return;
}
