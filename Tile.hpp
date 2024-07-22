#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include <string>
#include "Resource.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

namespace ariel {
    class Player; // Forward declaration

    class Tile {
    public:
        enum Type { FOREST, HILL, PASTURE, FIELD, MOUNTAIN, DESERT };

        Tile(Type type, int id);

        Type getType() const;
        int getNumber() const;
        Resource getResource() const;
        void setNumber(int number);
        void addVertex(Vertex* v);
        void addEdge(Edge* edge);
        std::string toString() const;
        std::vector<Vertex*>& getVertices();
        std::vector<Edge*>& getEdges();
        int getId() const;

    private:
        int id;
        Type type;
        int number;
        std::vector<std::pair<Player*, Player::CityType>> players;
        std::vector<Vertex*> vertices;
        std::vector<Edge*> edges;
    };
} // namespace ariel

#endif // TILE_HPP
