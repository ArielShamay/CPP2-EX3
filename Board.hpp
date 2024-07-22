#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
//#include "Tile.hpp"
//#include "Edge.hpp"
//#include "Vertex.hpp"

namespace ariel {
    class Player; // Forward declaration
    class Tile; // Forward declaration
    class Edge; // Forward declaration
    class Vertex; // Forward declaration
    class Board {
    public:
        Board();

        void initialize();
        Tile& getTile(int id);
        Edge& getEdge(int id);
        Vertex& getVertex(int id);
        void addTile(const Tile& tile);
        std::string toString() const;
        std::vector<Tile> tiles;
        std::vector<Edge> edges;
        std::vector<Vertex> vertices;

    private:
       
    };
} // namespace ariel

#endif // BOARD_HPP
