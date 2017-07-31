CC			=g++ -std=c++11
DEBUG		=-g
LFLAG		=-Wall $(DEBUG)
CFLAG		=-Wall -c $(DEBUG)
HEADERFILES	=define.h configure.h
CPPFILES	=main.cpp configure.cpp 
OBJFILES	=configure.o
EXEC		=CCC.exe

CCC.exe: main.cpp configure.o define.h
	$(CC) main.cpp $(LFLAG) -o $(EXEC) $(OBJFILES)

configure: configure.cpp configure.h define.h
	$(CC) configure.cpp $(CFLAG) -o configure.o

clean:
	\rm *.o *~ $(EXEC)
