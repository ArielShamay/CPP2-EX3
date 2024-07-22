#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include <string>

// Forward declaration of Vertex class
namespace ariel {
    class Vertex;
}

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
        std::vector<Vertex*>& getVertices(); // שינוי השם ל-getVertices במקום getVertexes

    private:
        int id;
        int sub_id;
        std::string player_id;
        std::vector<Edge*> neighbors;
        std::vector<Vertex*> vertices; // שינוי השם ל-vertices במקום vertexes
    };
} // namespace ariel

#endif // EDGE_HPP
