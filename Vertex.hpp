#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>
#include "Player.hpp"

namespace ariel {
    class Vertex {
    public:
        enum class CityType { NONE, SETTLEMENT, CITY };

        Vertex(int id);

        int getId() const;
        CityType getCityType() const;
        void setCityType(CityType cityType);
        std::string getPlayerId() const;
        void setPlayerId(const std::string& playerId);
        const std::vector<int>& getEdges() const; // הוספת הפונקציה הזאת

    private:
        int id;
        CityType cityType;
        std::string playerId;
        std::vector<int> edges; // רשימת הצלעות המקושרות לקודקוד הזה
    };
} // namespace ariel

#endif // VERTEX_HPP