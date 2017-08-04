CC			= g++
CXXFLAGS	= -std=c++11 -pthread
DEBUG		= -g
LFLAG		= -Wall $(DEBUG)
CFLAG		= -Wall -c $(DEBUG)
HEADERFILES	= define.h configure.h server.h c3server.h
CPPFILES	= main.cpp configure.cpp server.cpp c3server.cpp
OBJFILES	= configure.o server.o c3server.o
EXEC		= CCC.exe

CCC.exe: main.cpp configure.h server.h c3server.h define.h Makefile
	$(CC) $(CXXFLAGS) main.cpp $(LFLAG) -o $(EXEC) $(OBJFILES)

c3server: c3server.cpp c3server.h configure.h server.h Makefile
	$(CC) $(CXXFLAGS) c3server.cpp $(CFLAG) -o c3server.o
	
configure: configure.cpp configure.h define.h Makefile
	$(CC) $(CXXFLAGS) configure.cpp $(CFLAG) -o configure.o

server: server.cpp server.h configure.h	Makefile
	$(CC) $(CXXFLAGS) server.cpp $(CFLAG) -o server.o

clean:
	-rm *.o *~ $(EXEC)
