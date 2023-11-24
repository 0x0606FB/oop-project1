CC = g++ 

CFLAGS = -g -Wall -Werror 

CVER = 11

SRC = ./src
INC = ./include

EXE = test

OBJS = $(patsubst %.cpp,%.o,$(wildcard $(SRC)/*.cpp)) 

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) 
