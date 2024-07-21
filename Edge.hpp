#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include <string>
#include "Vertex.hpp" // Ensure Vertex is included

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
        std::vector<Vertex*>& getVertices(); // Change the function name to getVertices

    private:
        int id;
        int sub_id;
        std::string player_id;
        std::vector<Edge*> neighbors;
        std::vector<Vertex*> vertices; // Change the member name to vertices
    };
} // namespace ariel

#endif // EDGE_HPP
