#include "Vertex.hpp"

namespace ariel {
    Vertex::Vertex(int id) : id(id), cityType(CityType::NONE), playerId("") {}

    int Vertex::getId() const {
        return id;
    }

    Vertex::CityType Vertex::getCityType() const {
        return cityType;
    }

    void Vertex::setCityType(CityType cityType) {
        this->cityType = cityType;
    }

    std::string Vertex::getPlayerId() const {
        return playerId;
    }

    void Vertex::setPlayerId(const std::string& playerId) {
        this->playerId = playerId;
    }

    const std::vector<int>& Vertex::getEdges() const { // מימוש הפונקציה הזאת
        return edges;
    }
}