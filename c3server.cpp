#include "c3server.h"
#include <cstdlib>
#include <sys/socket.h>

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
		close(sockfd);
		
		std::vector<config_Entry*> temp = settings.return_Settings();
		
		for(auto it=temp.begin(); it<temp.end(); ++it){
			config_Entry* temp2 = (*it);
			if(temp2->command == command){
				if(temp2->auth_Code == auth_code){
					_(std::cout << temp2->program << "\n";)
					std::system(temp2->program.c_str());
				}
			}
		}
	}
	close(sockfd);
	return;
}

void C3Server::configure_settings(std::ifstream & configFile){
	settings.initialize(configFile);
	return;
}
