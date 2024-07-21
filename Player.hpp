#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include "Resource.hpp"
#include "DevelopmentCard.hpp"
#include "Board.hpp"
#include "Tile.hpp"

namespace ariel {
    class Player {
    public:
        enum class CityType { NONE, SETTLEMENT, CITY }; // שינוי השם ל-CityType במקום city

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

        void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
        void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
        void rollDice();
        void endTurn();
        void trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);
        void buyDevelopmentCard();
        void printPoints() const;

    private:
        std::string name;
        std::map<Resource, int> resources;
        std::vector<DevelopmentCard> developmentCards;
        int victoryPoints;
    };
} // namespace ariel

#endif // PLAYER_HPP
