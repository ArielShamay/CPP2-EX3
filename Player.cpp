#include "Player.hpp"

namespace ariel {
    Player::Player(const std::string& name) : name(name), victoryPoints(0) {}

    const std::string& Player::getName() const {
        return name;
    }

    void Player::addResource(Resource::Type resource, int amount) {
        resources[resource] += amount;
    }

    void Player::removeResource(Resource::Type resource, int amount) {
        resources[resource] -= amount;
    }

    int Player::getResourceCount(Resource::Type resource) const {
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
} // namespace ariel
