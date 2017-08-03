CC		=g++ -std=c++11
DEBUG		=-g
LFLAG		=-Wall $(DEBUG)
CFLAG		=-Wall -c $(DEBUG)
HEADERFILES	=define.h configure.h server.h c3server.h
CPPFILES	=main.cpp configure.cpp server.cpp c3server.cpp
OBJFILES	=configure.o server.o c3server.o
EXEC		=CCC.exe

CCC.exe: main.cpp configure.o server.o c3server.o define.h
	$(CC) main.cpp $(LFLAG) -o $(EXEC) $(OBJFILES)

configure: configure.cpp configure.h define.h
	$(CC) configure.cpp $(CFLAG) -o configure.o

server: server.cpp server.h configure.h	
	$(CC) server.cpp $(CFLAG) -o server.o

c3server: c3server.cpp c3server.h configure.h server.h
	$(CC) c3server.cpp $(CFLAG) -o c3server.o

clean:
	\rm *.o *~ $(EXEC)
