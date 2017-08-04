#pragma once

#include "server.h"
#include "configure.h"
#include <fstream>
#include <cstdlib>

class C3Server : public Server{
private:
	void handle_connection(int sockfd);

public:
	C3Server() {}
	~C3Server() {}
	void configure_settings(std::ifstream& configFile);
	Configure settings;
};