#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include "Resource.hpp"
#include "DevelopmentCard.hpp"

namespace ariel {
    
    class Tile;  // Forward declaration
    class Board; // Forward declaration

    class Player {
    public:
        Player(const std::string& name);

        const std::string& getName() const;
        int getId() const;
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

        void placeSettlement(int vertex, Board& board);
        void placeRoad(int edge, Board& board);
        void rollDice(Board& board);
        void endTurn(Board& board);
        void trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);
        void buyDevelopmentCard(DevelopmentCards& devCards); 
        void printPoints() const;

        void setAlreadyRolled(bool rolled);
        bool getAlreadyRolled() const;
        void reduceHalfResources();

    private:
        std::string name;
        int id;
        std::map<Resource, int> resources;
        std::vector<DevelopmentCard> developmentCards;
        int victoryPoints;
        bool alreadyRolled;
    };
} // namespace ariel

#endif // PLAYER_HPP
