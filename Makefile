#!make -f

CXX=g++  
CXXFLAGS=-g -Wall 
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES_DEMO=Demo.cpp Board.cpp Player.cpp Tile.cpp Edge.cpp Vertex.cpp Game.cpp DevelopmentCard.cpp
OBJECTS_DEMO=$(subst .cpp,.o,$(SOURCES_DEMO))

SOURCES_TEST=Board.cpp Player.cpp Tile.cpp Edge.cpp Vertex.cpp Game.cpp DevelopmentCard.cpp TestCounter.cpp Test.cpp
OBJECTS_TEST=$(subst .cpp,.o,$(SOURCES_TEST))

catan: main
	./$^

main: $(OBJECTS_DEMO)
	$(CXX) $(CXXFLAGS) $^ -o main

test: TestCounter.o Test.o $(OBJECTS_TEST)
	$(CXX) $(CXXFLAGS) $^ -o test

valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main test