CC=gcc
CFLAGS=-g -Wall
EXECUTABLE=test
test: testSuite.o btree.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) testSuite.o btree.o
testSuite.o: testSuite.cpp btree.h
	$(CC) $(CFLAGS) -c testSuite.cpp
btree.o: btree.cpp btree.h
	$(CC) $(CFLAGS) -c btree.cpp
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
