CC = gcc
CFLAGS = -fopenmp -Wall -g -I./src
SRC = src/main.c src/exe.c
OBJ = src/main.o src/exe.o
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) -fopenmp -lm

src/main.o: src/main.c src/trab.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/exe.o: src/exe.c src/trab.h 
	$(CC) $(CFLAGS) -c src/exe.c -o src/exe.o   # Corrigido para exe.c

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)
