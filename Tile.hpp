// Tile.hpp
#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "Resource.hpp"
#include "Edge.hpp"
#include "Player.hpp"

namespace ariel {
    class Tile {
    public:
        enum Type { FOREST, HILL, PASTURE, FIELD, MOUNTAIN, DESERT };

        Tile(Type type, int id);

        Type getType() const;
        int getNumber() const;
        Resource::Type getResource() const;
        void setNumber(int number);
        void addVertex(Vertex* v);
        void addEdge(Edge* edge);
        std::string toString() const;
        std::vector<Vertex*>& getVertices();

    private:
        Type type;
        int number;
        std::vector<std::pair<Player*, city>> players;
        std::vector<Vertex*> vertices;
        std::vector<Edge*> edges;
    };
} // namespace ariel

#endif // TILE_HPP
