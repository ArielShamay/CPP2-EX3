#include "Player.hpp"
#include "Board.hpp"
#include "Tile.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_set>

namespace ariel {
    Player::Player(const std::string& name) : name(name), victoryPoints(0), alreadyRolled(false) {}

    const std::string& Player::getName() const {
        return name;
    }
    int Player::getId() const { // הוספת הפונקציה getId
        return id;
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
        addResource(Resource::WOOD, -1);
        addResource(Resource::BRICK, -1);
        addResource(Resource::WOOL, -1);
        addResource(Resource::GRAIN, -1);
        addVictoryPoints(1);
        std::cout << name << " builds a settlement" << std::endl;
    }

    void Player::buildCity() {
        addResource(Resource::ORE, -3);
        addResource(Resource::GRAIN, -2);
        addVictoryPoints(1);
        std::cout << name << " builds a city" << std::endl;
    }

    void Player::buildRoad() {
        addResource(Resource::WOOD, -1);
        addResource(Resource::BRICK, -1);
        std::cout << name << " builds a road" << std::endl;
    }

    int Player::getVictoryPoints() const {
        return victoryPoints;
    }

    void Player::addVictoryPoints(int points) {
        victoryPoints += points;
    }
 void Player::placeSettlement(int vertex, Board& board) {
        if (board.canBuildSettlement(vertex, *this)) {
            board.buildSettlement(vertex, *this);
        } else {
            std::cout << "Cannot build settlement at vertex " << vertex << std::endl;
        }
    }

    void Player::placeRoad(int edge, Board& board) {
        if (board.canBuildRoad(edge, *this)) {
            board.buildRoad(edge, *this);
        } else {
            std::cout << "Cannot build road at edge " << edge << std::endl;
        }
    }
    void Player::rollDice(Board& board) {
    if (board.getPlayerTurn() != getId()) {
        std::cout << "It's not your turn" << std::endl;
        return;
    }
    if (alreadyRolled) {
        std::cout << "You have already rolled the dice this turn" << std::endl;
        return;
    }

    int diceRoll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1); // Roll two dice
    std::cout << name << " rolled a " << diceRoll << std::endl;
    board.shareResources(diceRoll);
    alreadyRolled = true;
}

void Player::endTurn(Board& board) {
    if (board.getPlayerTurn() != getId()) {
        std::cout << "It's not your turn" << std::endl;
        return;
    }
    std::cout << name << " ends their turn" << std::endl;
    if (!getAlreadyRolled()) {
        rollDice(board);
    }
    board.nextTurn();
}
    void Player::trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount) {
        Resource give = Resource::NONE;
        Resource get = Resource::NONE;

        if (giveResource == "WOOD") give = Resource::WOOD;
        else if (giveResource == "BRICK") give = Resource::BRICK;
        else if (giveResource == "WOOL") give = Resource::WOOL;
        else if (giveResource == "GRAIN") give = Resource::GRAIN;
        else if (giveResource == "ORE") give = Resource::ORE;

        if (getResource == "WOOD") get = Resource::WOOD;
        else if (getResource == "BRICK") get = Resource::BRICK;
        else if (getResource == "WOOL") get = Resource::WOOL;
        else if (getResource == "GRAIN") get = Resource::GRAIN;
        else if (getResource == "ORE") get = Resource::ORE;

        if (give != Resource::NONE && get != Resource::NONE && getResourceCount(give) >= giveAmount) {
            removeResource(give, giveAmount);
            addResource(get, getAmount);
            other.removeResource(get, getAmount);
            other.addResource(give, giveAmount);
            std::cout << name << " trades " << giveAmount << " " << giveResource << " with " << other.getName() << " for " << getAmount << " " << getResource << std::endl;
        } else {
            std::cout << "Invalid trade!" << std::endl;
        }
    }

    void Player::buyDevelopmentCard(DevelopmentCards& devCards) {
    if (getResourceCount(Resource::GRAIN) < 1 || getResourceCount(Resource::WOOL) < 1 || getResourceCount(Resource::ORE) < 1) {
        std::cout << "Not enough resources to buy a development card!" << std::endl;
        return;
    }
    removeResource(Resource::GRAIN, 1);
    removeResource(Resource::WOOL, 1);
    removeResource(Resource::ORE, 1);

    DevelopmentCard card = devCards.drawCard();
    addDevelopmentCard(card);

    std::cout << name << " buys a development card" << std::endl;
}


    void Player::printPoints() const {
        std::cout << name << " has " << victoryPoints << " points" << std::endl;
    }

    void Player::setAlreadyRolled(bool rolled) {
        alreadyRolled = rolled;
    }

    bool Player::getAlreadyRolled() const {
        return alreadyRolled;
    }

    void Player::reduceHalfResources() {
        std::cout << "Reducing half resources for player " << name << std::endl;
        int totalResources = 0;
        for (const auto& res : resources) {
            totalResources += res.second;
        }
        if (totalResources > 7) {
            int resourcesToRemove = totalResources / 2;
            for (auto& res : resources) {
                int removeAmount = std::min(res.second, resourcesToRemove);
                res.second -= removeAmount;
                resourcesToRemove -= removeAmount;
                if (resourcesToRemove <= 0) break;
            }
        }
    }
} // namespace ariel
