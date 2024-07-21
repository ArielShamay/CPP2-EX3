#include "Edge.hpp"

namespace ariel {
    Edge::Edge(int id, int sub_id) : id(id), sub_id(sub_id), player_id("") {}

    bool Edge::operator==(const Edge& rhs) const {
        return id == rhs.id && sub_id == rhs.sub_id;
    }

    int Edge::getId() const {
        return id;
    }

    int Edge::getSubId() const {
        return sub_id;
    }

    void Edge::addNeighbor(Edge* e) {
        neighbors.push_back(e);
    }

    std::vector<Edge*>& Edge::getNeighbors() {
        return neighbors;
    }

    void Edge::setPlayerId(const std::string& id) {
        player_id = id;
    }

    std::string Edge::getPlayerId() const {
        return player_id;
    }

    void Edge::addVertex(Vertex* v) {
        vertices.push_back(v);
    }

    std::vector<Vertex*>& Edge::getVertices() {
        return vertices; // Change the function implementation to return vertices
    }
} // namespace ariel
