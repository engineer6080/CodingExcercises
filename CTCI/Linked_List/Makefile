CXX=g++
DEPS = ll.hpp
CFLAGS=-I.
OBJ = test.o

test: $(OBJ)
	@$(CXX) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	@$(CXX) -c $< -o $@

clean:
	-@rm -rf *.o 2>/dev/null || true
