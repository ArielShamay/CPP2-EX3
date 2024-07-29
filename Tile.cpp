#include "Tile.hpp"
#include "Player.hpp"

namespace ariel {
    Tile::Tile(Type type, int id) : id(id), type(type), number(0) {
        vertices.resize(6);
        edges.resize(6);
    }

    Tile::Type Tile::getType() const {
        return type;
    }

    int Tile::getNumber() const {
        return number;
    }

    Resource Tile::getResource() const {
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

    void Tile::addVertex(int v1, int v2, int v3, int v4, int v5, int v6) {
        vertices[0] = v1;
        vertices[1] = v2;
        vertices[2] = v3;
        vertices[3] = v4;
        vertices[4] = v5;
        vertices[5] = v6;
    }

    std::vector<int> Tile::getVertices() const {
        return vertices;
    }

    void Tile::addEdge(int edge) {
        edges.push_back(edge);
    }

    std::vector<int> Tile::getEdges() const {
        return edges;
    }

    int Tile::getId() const {
        return id;
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
    void Tile::setVertices(const std::vector<int>& vertices) {
    this->vertices = vertices;
}

}
