#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include <string>
#include "Resource.hpp"
#include "Edge.hpp"
#include "Tile.hpp"

namespace ariel {
    class Vertex {
    public:
        enum class city { NONE, SETTLEMENT, CITY };

        Vertex(int id);

        int getId() const;
        void addNeighbor(Vertex* v);
        std::vector<Vertex*>& getNeighbors();
        void setCityType(city type);
        city getCityType() const;
        void setPlayerId(const std::string& id);
        std::string getPlayerId() const;

    private:
        int id;
        city cityType;
        std::vector<Vertex*> neighbors;
        std::string playerId;
    };
} // namespace ariel

#endif // VERTEX_HPP
