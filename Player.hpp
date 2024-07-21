#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include "Resource.hpp"
#include "DevelopmentCard.hpp"

namespace ariel {
    class Player {
    public:
        enum class city { NONE, SETTLEMENT, CITY }; // הוספת הגדרת city

        Player(const std::string& name);

        const std::string& getName() const;
        void addResource(Resource resource, int amount);
        void removeResource(Resource resource, int amount);
        int getResourceCount(Resource resource) const;

        void addDevelopmentCard(const DevelopmentCard& card);
        const std::vector<DevelopmentCard>& getDevelopmentCards() const;

        void buildSettlement();
        void buildCity();
        void buildRoad();

        int getVictoryPoints() const;
        void addVictoryPoints(int points);

    private:
        std::string name;
        std::map<Resource, int> resources;
        std::vector<DevelopmentCard> developmentCards;
        int victoryPoints;
    };
} // namespace ariel

#endif // PLAYER_HPP
