#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include <string>
#include "Resource.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

namespace ariel {
    class Player; // Forward declaration
    class Vertex; // Forward declaration
    class Edge; // Forward declaration

    class Tile {
    public:
        enum Type { FOREST, HILL, PASTURE, FIELD, MOUNTAIN, DESERT };

        Tile(); // קונסטרקטור ברירת מחדל
        Tile(int id, Type type, int number); // קונסטרקטור חדש
        Tile(Type type, int id);
        Type getType() const;
        int getNumber() const;
        Resource getResource() const;
        void setNumber(int number);
        void addVertex(int v1, int v2, int v3, int v4, int v5, int v6);
        std::vector<int> getVertices() const;
        void addEdge(int edge);
        std::vector<int> getEdges() const;
        int getId() const;
        std::string toString() const;
        void setVertices(const std::vector<int>& vertices);

    private:
        int id;
        Type type;
        int number;
        std::vector<int> vertices;
        std::vector<int> edges;
    };
} // namespace ariel

#endif // TILE_HPP
