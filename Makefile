CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS =

SRCS = main.cpp Tile.cpp Edge.cpp Test.cpp
HEADERS = Tile.hpp Edge.hpp

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
