#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

namespace ariel {
    class Player; // Forward declaration

    class Board {
    public:
        Board();

        void initialize();
        Tile& getTile(int id);
        Edge& getEdge(int id);
        Vertex& getVertex(int id);
        void addTile(const Tile& tile);
        std::string toString() const;

    private:
        std::vector<Tile> tiles;
        std::vector<Edge> edges;
        std::vector<Vertex> vertices;
    };
} // namespace ariel

#endif // BOARD_HPP
