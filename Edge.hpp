#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include <string>

namespace ariel {
    class Vertex; // Forward declaration

    class Edge {
    public:
        Edge(int id, int sub_id);

        bool operator==(const Edge& rhs) const;

        int getId() const;
        int getSubId() const;
        void addNeighbor(Edge* e);
        std::vector<Edge*>& getNeighbors();
        void setPlayerId(const std::string& id);
        std::string getPlayerId() const;
        void addVertex(Vertex* v);
        std::vector<Vertex*>& getVertices();

    private:
        int id;
        int sub_id;
        std::string player_id;
        std::vector<Edge*> neighbors;
        std::vector<Vertex*> vertices;
    };
} // namespace ariel

#endif // EDGE_HPP
