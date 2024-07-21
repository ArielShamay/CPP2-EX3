// Edge.hpp
#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include <string>
#include "Vertex.hpp"

namespace ariel {
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
        std::vector<Vertex*>& getVertexes();

    private:
        int id;
        int sub_id;
        std::vector<Edge*> neighbors;
        std::string player_id;
        std::vector<Vertex*> vertexes;
    };
} // namespace ariel

#endif // EDGE_HPP
