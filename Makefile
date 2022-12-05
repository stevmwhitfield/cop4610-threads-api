CC = gcc

CFLAGS = -pthread

TARGET = main

main:
	$(CC) $(CFLAGS) ./src/main.c -o main

clean:
	rm -rf main