#include "Vertex.hpp"

namespace ariel {
    Vertex::Vertex(int id) : id(id), cityType(city::NONE), playerId("") {}

    int Vertex::getId() const {
        return id;
    }

    void Vertex::addNeighbor(Vertex* v) {
        neighbors.push_back(v);
    }

    std::vector<Vertex*>& Vertex::getNeighbors() {
        return neighbors;
    }

    void Vertex::setCityType(city type) {
        cityType = type;
    }

    Vertex::city Vertex::getCityType() const {
        return cityType;
    }

    void Vertex::setPlayerId(const std::string& id) {
        playerId = id;
    }

   std::string Vertex::getPlayerId() const {
        return playerId;
    }
} // namespace ariel
