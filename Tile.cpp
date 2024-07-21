// Tile.cpp
#include "Tile.hpp"

namespace ariel {
    Tile::Tile(Type type, int id) : id(id), type(type) {}

    Tile::Type Tile::getType() const {
        return type;
    }

    int Tile::getNumber() const {
        return number;
    }

    Resource::Type Tile::getResource() const {
        switch (type) {
            case FOREST: return Resource::WOOD;
            case HILL: return Resource::BRICK;
            case PASTURE: return Resource::WOOL;
            case FIELD: return Resource::GRAIN;
            case MOUNTAIN: return Resource::ORE;
            default: return Resource::NONE;
        }
    }

    void Tile::setNumber(int number) {
        this->number = number;
    }

    void Tile::addVertex(Vertex* v) {
        vertices.push_back(v);
    }

    void Tile::addEdge(Edge* edge) {
        edges.push_back(edge);
    }

    std::string Tile::toString() const {
        std::string s;
        switch (type) {
            case FOREST: s = "FOREST"; break;
            case HILL: s = "HILL"; break;
            case PASTURE: s = "PASTURE"; break;
            case FIELD: s = "FIELD"; break;
            case MOUNTAIN: s = "MOUNTAIN"; break;
            default: s = "DESERT"; break;
        }
        if (s == "DESERT") return s;
        s += " " + std::to_string(number);
        return s;
    }

    std::vector<Vertex*>& Tile::getVertices() {
        return vertices;
    }
} // namespace ariel
