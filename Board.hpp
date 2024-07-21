#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

namespace ariel {
    class Board {
    public:
        Board();

        void initialize();
        Tile& getTile(int id);
        Edge& getEdge(int id);
        Vertex& getVertex(int id);

    private:
        std::vector<Tile> tiles;
        std::vector<Edge> edges;
        std::vector<Vertex> vertices;
    };
} // namespace ariel

#endif // BOARD_HPP
