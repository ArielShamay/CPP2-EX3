#include "Board.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"
#include "Tile.hpp"
#include <stdexcept>
#include <sstream>

namespace ariel {
    Board::Board() {
        // Initialize the board here if needed
    }

    void Board::initialize() {
        // Initialize the tiles, edges, and vertices here
    }

    Tile& Board::getTile(int id) {
        for (auto& tile : tiles) {
            if (tile.getId() == id) {
                return tile;
            }
        }
        throw std::out_of_range("Tile with given ID not found");
    }

    Edge& Board::getEdge(int id) {
        for (auto& edge : edges) {
            if (edge.getId() == id) {
                return edge;
            }
        }
        throw std::out_of_range("Edge with given ID not found");
    }

    Vertex& Board::getVertex(int id) {
        for (auto& vertex : vertices) {
            if (vertex.getId() == id) {
                return vertex;
            }
        }
        throw std::out_of_range("Vertex with given ID not found");
    }

    void Board::addTile(const Tile& tile) {
        tiles.push_back(tile);
    }

    std::string Board::toString() const {
        std::ostringstream oss;
        for (const auto& tile : tiles) {
            oss << tile.toString() << "\n";
        }
        return oss.str();
    }
}
