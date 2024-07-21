CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I/home/ariel/CPP2-EX3 -I/home/ariel/CPP2-EX3/doctest
LDFLAGS =

SRCS = Test.cpp Tile.cpp Edge.cpp
HEADERS = Tile.hpp Edge.hpp Resource.hpp doctest/doctest.h

OBJS = $(SRCS:.cpp=.o)

all: catan

catan: $(OBJS)
	$(CXX) $(LDFLAGS) -o catan $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o catan

test: all
	./catan
