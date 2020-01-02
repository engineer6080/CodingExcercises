CC=gcc
CFLAGS=-Wall
EXECUTABLE=test
test: queue.o testSuite.c
	$(CC) $(CFLAGS) queue.o testSuite.c -o $(EXECUTABLE)
queue.o: queue.c queue.h
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
