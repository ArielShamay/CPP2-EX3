CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I/home/ariel/CPP2-EX3 -I/home/ariel/CPP2-EX3/doctest
LDFLAGS =

SRCS = Demo.cpp Tile.cpp Edge.cpp Vertex.cpp Player.cpp DevelopmentCard.cpp Game.cpp Board.cpp Resource.cpp
HEADERS = Tile.hpp Edge.hpp Vertex.hpp Resource.hpp Player.hpp DevelopmentCard.hpp Game.hpp Board.hpp doctest/doctest.h

OBJS = $(SRCS:.cpp=.o)

all: catan

catan: $(OBJS)
	$(CXX) $(LDFLAGS) -o catan $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o catan

test: catan
	./catan
