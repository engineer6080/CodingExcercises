CC=gcc
CFLAGS=-Wall
EXECUTABLE=test
test: llist.o testSuite.c
	$(CC) $(CFLAGS) llist.o testSuite.c -o $(EXECUTABLE)
llist.o: llist.h
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
