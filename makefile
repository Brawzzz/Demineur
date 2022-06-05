CC = gcc
SRC = $(wilcard *.c)
OBJ = $(SRC :.c = .o)

all : demineur

tools.o : tools.c
	$(CC) -c $< -o $@
	
Game.o : Game.c Game.h tools.h
	$(CC) -c $< -o $@
	
display.o : display.c display.h tools.h
	$(CC) -c $< -o $@

Player.o : Player.c Player.h
	$(CC) -c $< -o $@
	
main.o : main.c Game.h display.h tools.h Box.h Player.h
	$(CC) -c $< -o $@

demineur : main.o Game.o display.o Player.o tools.o 
	$(CC) $^ -o $@
