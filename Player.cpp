#include "Player.hpp"
#include "Board.hpp"
#include "Tile.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_set>

namespace ariel {
    Player::Player(const std::string& name) : name(name), victoryPoints(0) {}

    const std::string& Player::getName() const {
        return name;
    }

    void Player::addResource(Resource resource, int amount) {
        resources[resource] += amount;
    }

    void Player::removeResource(Resource resource, int amount) {
        resources[resource] -= amount;
    }

    int Player::getResourceCount(Resource resource) const {
        auto it = resources.find(resource);
        return it != resources.end() ? it->second : 0;
    }

    void Player::addDevelopmentCard(const DevelopmentCard& card) {
        developmentCards.push_back(card);
    }

    const std::vector<DevelopmentCard>& Player::getDevelopmentCards() const {
        return developmentCards;
    }

    void Player::buildSettlement() {
        // Implementation here
    }

    void Player::buildCity() {
        // Implementation here
    }

    void Player::buildRoad() {
        // Implementation here
    }

    int Player::getVictoryPoints() const {
        return victoryPoints;
    }

    void Player::addVictoryPoints(int points) {
        victoryPoints += points;
    }

    void Player::placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    // Assuming places[0] and placesNum[0] determine the location on the board
    Tile& tile = board.getTile(placesNum[0]);

    // Check if the location is valid for placing a settlement
    bool validLocation = true; // Add logic to determine if the location is valid

    if (validLocation) {
        // Assuming Tile has a method to add a settlement associated with the player
        tile.addSettlement(this);

        // Update player's resources and victory points if needed
        this->buildSettlement();

        std::cout << name << " places a settlement at " << places[0] << " with number " << placesNum[0] << std::endl;
    } else {
        std::cout << "Invalid location for settlement!" << std::endl;
    }
}
    void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    if (places.empty() || placesNum.empty()) {
        std::cerr << "Error: places or placesNum is empty." << std::endl;
        return;
    }

    std::unordered_set<std::string> placesSet(places.begin(), places.end());
    bool roadPlaced = false;

    for (const auto& tile : board.getTiles()) {
        if (placesSet.find(tile.toString()) != placesSet.end()) {
            for (auto& edge : tile.getEdges()) {
                for (auto& vertex : edge->getVertices()) {
                    if (vertex->getPlayerId() == name) {
                        // Implement the logic for placing a road
                        // Example: edge->setHasRoad(true);
                        // Note: You'll need to add a method in your Edge class to mark the road as placed.
                        std::cout << name << " places a road at " << tile.toString() << std::endl;
                        roadPlaced = true;
                        break; // Assuming one road placement per call, break out of the loops.
                    }
                }
                if (roadPlaced) break;
            }
        }
        if (roadPlaced) break;
    }

    if (!roadPlaced) {
        std::cerr << "Error: Unable to place a road for " << name << std::endl;
    }
}
     void Player::rollDice() {
        // Implementation here
        std::cout << name << " rolls the dice" << std::endl;
    }

    void Player::endTurn() {
        // Implementation here
        std::cout << name << " ends their turn" << std::endl;
    }

    void Player::trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount) {
        // Implementation here
        std::cout << name << " trades " << giveAmount << " " << giveResource << " with " << other.getName() << " for " << getAmount << " " << getResource << std::endl;
    }

    void Player::buyDevelopmentCard() {
        // Implementation here
        std::cout << name << " buys a development card" << std::endl;
    }

    void Player::printPoints() const {
        std::cout << name << " has " << victoryPoints << " points" << std::endl;
    }
} // namespace ariel
