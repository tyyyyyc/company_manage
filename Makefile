CC=g++
LIB=-lm -lmysqlclient
INC=-I./include
OBJ=main.o serviceview_console_impl.o managerview_console_impl.o \
service_impl.o managerservice_impl.o tools.o sql.o
BIN=a.out
Flag=-Wall -Werror

all:$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(BIN)

%.o:%.cpp
	$(CC) $(FLAG) $(INC) -c $< -o $@

clean:
	rm $(OBJ) $(BIN)

