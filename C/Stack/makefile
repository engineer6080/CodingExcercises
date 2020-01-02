CC=gcc
CFLAGS=-Wall
EXECUTABLE=test
test: stack.o testSuite.c
	$(CC) $(CFLAGS) stack.o testSuite.c -o $(EXECUTABLE)
stack.o: stack.c stack.h
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
