#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include <string>

namespace ariel {
    class Vertex; // Forward declaration

    class Edge {
    public:
        Edge(int id); // עדכון הבנאי ללקיחת מזהה יחיד

        bool operator==(const Edge& rhs) const;

        int getId() const;
        void addNeighbor(Edge* e);
        std::vector<Edge*>& getNeighbors();
        void setPlayerId(const std::string& id);
        std::string getPlayerId() const;
        void addVertex(int v);
        void addVertices(int v1, int v2); // פונקציה להוספת שני קודקודים בבת אחת
        std::vector<int> getVertices() const; // חזרת המזהים של הקודקודים

    private:
        int id;
        std::string player_id;
        std::vector<Edge*> neighbors;
        std::vector<int> vertices; // רשימת מזהי הקודקודים המקושרים לצלע
    };
} // namespace ariel

#endif // EDGE_HPP
