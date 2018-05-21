#pragma once

#include <string.h>
#include <iostream>

class Server{
	private:
		virtual void handle_connection(int sockfd);
	public:
		Server() {}
		void initialize(int port, bool daemon);
		void start_listening(int socket);
		void authenticate(int sockfd);
		void sendMessage(int sockfd, std::string prompt);
		~Server() {}
};
