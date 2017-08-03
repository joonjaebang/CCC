#include "c3server.h"

void C3Server::handle_connection(int sockfd){
	char buffer[256];
	while(recv(sockfd, buffer, 255, 0) > 0){
		std::string command, auth_string;
		int authorization;
// 		std::cout << buffer;
// 		send(sockfd, (void*)responseChar, strlen(responseChar), MSG_NOSIGNAL);
		std::stringstream ss;
		ss << buffer;
		std::getline(ss, command, '#');
		std::getline(ss, auth_string, '#');
		authorization = std::atoi(auth_string.c_str());
		bzero(buffer, 256);
	}
	return;
}

void C3Server::configure_settings(std::ifstream & configFile){
	settings.initialize(configFile);
	return;
}
