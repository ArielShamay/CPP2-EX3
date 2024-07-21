#include "Player.hpp"
#include <iostream>

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

    void Player::placeSettelemnt(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
        // Implementation here
        std::cout << name << " places a settlement at " << places[0] << " with number " << placesNum[0] << std::endl;
    }

    void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
        // Implementation here
        std::cout << name << " places a road at " << places[0] << " with number " << placesNum[0] << std::endl;
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
