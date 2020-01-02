CC=gcc
CFLAGS=-g -Wall
EXECUTABLE=test
test: testSuite.o tree.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) testSuite.o tree.o
testSuite.o: testSuite.c tree.h
	$(CC) $(CFLAGS) -c testSuite.c
tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
