#include "Edge.hpp"

namespace ariel {

    Edge::Edge(int id) : id(id), player_id("") {} // עדכון הבנאי ללקיחת מזהה יחיד

    bool Edge::operator==(const Edge& rhs) const {
        return id == rhs.id;
    }

    int Edge::getId() const {
        return id;
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

    void Edge::addVertex(int v) {
        vertices.push_back(v);
    }

    void Edge::addVertices(int v1, int v2) { // הוספת שני קודקודים למערך
        vertices.push_back(v1);
        vertices.push_back(v2);
    }

    std::vector<int> Edge::getVertices() const { // החזרת רשימת הקודקודים
        return vertices;
    }
}
