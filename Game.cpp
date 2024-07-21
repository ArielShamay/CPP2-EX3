#include "Game.hpp"
#include <iostream>

namespace ariel {
    Game::Game(const std::vector<Player>& players) : players(players), currentPlayerIndex(0), gameOver(false) {}

    void Game::start() {
        // Implementation here
    }

    void Game::playTurn(Player& player) {
        // Implementation here
    }

    void Game::rollDice(Player& player) {
        // Implementation here
    }

    void Game::buildSettlement(Player& player) {
        // Implementation here
    }

    void Game::buildCity(Player& player) {
        // Implementation here
    }

    void Game::buildRoad(Player& player) {
        // Implementation here
    }

    void Game::buyDevelopmentCard(Player& player) {
        // Implementation here
    }

    void Game::endTurn(Player& player) {
        // Implementation here
    }

    bool Game::isGameOver() const {
        return gameOver;
    }

    Player Game::getWinner() const {
        // Implementation here
        return players[0]; // Placeholder
    }

    void Game::printWinner() const {
        if (isGameOver()) {
            std::cout << "Winner: " << getWinner().getName() << std::endl;
        } else {
            std::cout << "No winner yet." << std::endl;
        }
    }

    Board Game::getBoard() const {
        return board;
    }
} // namespace ariel
