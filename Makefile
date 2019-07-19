CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra

BIN		:= bin
SRC		:= src

INCLUDE	:= D:/Perso/Informatique/CPP/_Includes/SFML-2.5.1/include
LIB		:= D:/Perso/Informatique/CPP/_Includes/SFML-2.5.1/lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)