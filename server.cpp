#include "define.h"
#include "server.h"
#include <map>
#include <thread>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>

void Server::initialize(int port, bool daemon){
	if(daemon){
		pid_t process_id = 0;
		pid_t sid = 0;
		
		process_id = fork();	
		if(process_id < 0){
			perror("Error: Failed to create child process.\n");
			exit(1);
		}

		if(process_id > 0){
			printf("Success: Created child process.\n");
			exit(0);
		}
		
		umask(0);
		sid = setsid();
		if(sid < 0){
			perror("Error: Failed to set sid.\n");
		}
		
		process_id = fork();
		if(process_id < 0){
			perror("Error: Failed double fork.\n");
			exit(1);
		}

		if(process_id > 0){
			printf("Success: Double fork.\n");
			exit(0);
		}

		chdir("/tmp");

		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}

	int sockfd;
	struct sockaddr_in serv_addr;
	
	//Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("Error: Failed to initialize socket.\n");
		exit(1);
	}
	
	//Bind socket
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family 		= AF_INET;
	serv_addr.sin_port			= htons(port);
	serv_addr.sin_addr.s_addr	= INADDR_ANY;
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		perror("Error: Failed to bind socket to address.\n");
		exit(1);
	}
	
	start_listening(sockfd);
	return;
}

void Server::start_listening(int socket){
	while(1){
		int newsockfd = -1;
		struct sockaddr_in client_addr;
		socklen_t client_len = sizeof(client_addr);
	
		listen(socket, 5);
		newsockfd = accept(socket, (struct sockaddr *) &client_addr, &client_len);
	
		if(newsockfd < 0){
			perror("Error: Failed to connect to incoming connection.\n");
			exit(1);
		}

		//Start new thread to handle request
		std::thread t1 (&Server::handle_connection, this, newsockfd);
		t1.detach();
	}
}

void Server::handle_connection(int sockfd){
	char buffer[256];
	std::string response = "Thank you for your response.\n";
	const char* responseChar = response.c_str();
	authenticate(sockfd);
	while(recv(sockfd, buffer, 255, 0) > 0){
		std::cout << buffer;
		send(sockfd, (void*)responseChar, strlen(responseChar), MSG_NOSIGNAL);
		bzero(buffer, 256);
	}
	close(sockfd);
	return;
}

void Server::authenticate(int sockfd){
// 	char buffer[256];
// 	std::string username, password;
// 	sendMessage(sockfd, "Please enter your username: ");
// 	bzero(buffer, 255);
// 	if(recv(sockfd, buffer, 255, 0) > 0){
// 		username = (std::string)buffer;
// 		username = username.substr(0, username.length()-1);
// 		_(std::cout << "Entered username: " << username << "\n";)
// 		if(authentication.find(username) == authentication.end()){
// 			std::cout << "Error: Invalid username\n";
// 			sendMessage(sockfd, "Invalid username. Closing connection.\n");
// 			close(sockfd);
// 		}
// 	}
// 
// 
// 	sendMessage(sockfd, "Please enter the password: ");
// 	bzero(buffer, 255);
// 	if(recv(sockfd, buffer, 255, 0) > 0){
// 		password = (std::string)buffer;
// 		password = password.substr(0, password.length()-1);
// 		_(std::cout << "Entered password: " << password << "\n";)
// 		if(authentication[username] != password){
// 			std::cout << "Error: Invalid password\n";
// 			sendMessage(sockfd, "Invalid password. Closing connection.\n");
// 			close(sockfd);
// 		}
// 	}
// 	
}

void Server::sendMessage(int sockfd, std::string prompt){
	const char * promptChar = prompt.c_str();
	send(sockfd, (void*)promptChar, strlen(promptChar), MSG_NOSIGNAL);
}
