all:run 
CC=g++
CFLAGS=-O1 -Wall -std=c++17 -Wno-missing-braces -I ./include/ -L ./lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET=floppa.exe
SRC=src/main.cpp src/grass.cpp
DEPS=src/objects.hpp
$(TARGET): $(SRC) $(DEPS) Makefile
	$(CC) $< -o $@ $(CFLAGS)
build: $(TARGET)
run: build
	./$(TARGET)

