CC = c99
SRC = ./src/ish.c ./src/liner.c ./src/parser.c 

main:
	$(CC) -o ish $(SRC) 
