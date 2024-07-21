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
        Player(const std::string& name);

        const std::string& getName() const;
        void addResource(Resource::Type resource, int amount);
        void removeResource(Resource::Type resource, int amount);
        int getResourceCount(Resource::Type resource) const;

        void addDevelopmentCard(const DevelopmentCard& card);
        const std::vector<DevelopmentCard>& getDevelopmentCards() const;

        void buildSettlement();
        void buildCity();
        void buildRoad();

        int getVictoryPoints() const;
        void addVictoryPoints(int points);

    private:
        std::string name;
        std::map<Resource::Type, int> resources;
        std::vector<DevelopmentCard> developmentCards;
        int victoryPoints;
    };
} // namespace ariel

#endif // PLAYER_HPP
