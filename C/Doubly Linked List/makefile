CC=gcc
CFLAGS=-Wall
EXECUTABLE=testdll
test: dllist.o testSuite.c
	$(CC) $(CFLAGS) dllist.o testSuite.c -o $(EXECUTABLE)
dllist.o: dllist.h dllist.c
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
