#include "Game.hpp"
#include <iostream>
#include <cstdlib> // עבור הפונקציה rand
#include <ctime> // עבור הפונקציה time

namespace ariel {
    Game::Game(const std::vector<Player>& players) : players(players), currentPlayerIndex(0), gameOver(false) {
        std::srand(std::time(0)); // אתחול ה-random seed
    }

    void Game::start() {
        // התחלת המשחק
        board.initialize(); // אתחול הלוח
        ChooseStartingPlayer(); // בחירת השחקן המתחיל
        while (!isGameOver()) {
            playTurn(players[currentPlayerIndex]);
        }
        printWinner(); // הדפסת המנצח בסוף המשחק
    }

    void Game::playTurn(Player& player) {
        rollDice(player); // זריקת קוביות

        // פעולות נוספות בתור של השחקן
        buildSettlement(player);
        buildCity(player);
        buildRoad(player);
        buyDevelopmentCard(player);

        // סיום התור
        endTurn(player);

        // בדיקה אם המשחק נגמר
        if (player.getVictoryPoints() >= 10) {
            gameOver = true;
        }
    }

    void Game::rollDice(Player& player) {
        // הטלת הקוביות
        int diceRoll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1); // הטלת שתי קוביות
        std::cout << player.getName() << " rolled a " << diceRoll << std::endl;
    }

    void Game::buildSettlement(Player& player) {
        // בניית יישוב
        std::vector<std::string> places = {"Forest", "Hills", "Fields"};
        std::vector<int> placesNum = {5, 6, 3};
        player.placeSettlement(places, placesNum, board);
    }

    void Game::buildCity(Player& player) {
        // בניית עיר
        std::cout << player.getName() << " builds a city." << std::endl;
    }

    void Game::buildRoad(Player& player) {
        // בניית דרך
        std::vector<std::string> places = {"Forest", "Hills"};
        std::vector<int> placesNum = {5, 6};
        player.placeRoad(places, placesNum, board);
    }

    void Game::buyDevelopmentCard(Player& player) {
        // קניית קלף פיתוח
        std::cout << player.getName() << " buys a development card." << std::endl;
    }

    void Game::endTurn(Player& player) {
        // סיום תור השחקן
        std::cout << player.getName() << " ends their turn" << std::endl;
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    bool Game::isGameOver() const {
        return gameOver;
    }

    Player Game::getWinner() const {
        // חזרה על השחקן המנצח
        for (const Player& player : players) {
            if (player.getVictoryPoints() >= 10) {
                return player;
            }
        }
        // במקרה שאין מנצח, נחזיר את השחקן הראשון
        return players[0];
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

    void Game::ChooseStartingPlayer() {
        currentPlayerIndex = std::rand() % players.size();
        std::cout << "Starting player: " << players[currentPlayerIndex].getName() << std::endl;
    }
}
