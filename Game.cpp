#include "Game.hpp"
#include <iostream>
#include <cstdlib> // עבור הפונקציה rand
#include <ctime> // עבור הפונקציה time

namespace ariel {
    Game::Game(const std::vector<Player>& players)
        : players(players), currentPlayerIndex(0), gameOver(false),
          board(players[0], players[1], players[2]), devCards() {
        std::srand(std::time(0)); // אתחול ה-random seed
    }

    void Game::start() {
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
        player.rollDice(board);
    }

    void Game::buildSettlement(Player& player) {
        player.placeSettlement(5, board); // דוגמה למזהה של קודקוד
    }

    void Game::buildCity(Player& player) {
        std::cout << player.getName() << " builds a city." << std::endl;
        // כאן תוסיף את הלוגיקה לבניית עיר אם יש צורך
    }

    void Game::buildRoad(Player& player) {
        player.placeRoad(1, board); // דוגמה למזהה של קצה
    }

    void Game::buyDevelopmentCard(Player& player) {
        player.buyDevelopmentCard(devCards);
    }

    void Game::endTurn(Player& player) {
        player.endTurn(board);
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    bool Game::isGameOver() const {
        return gameOver;
    }

    Player Game::getWinner() const {
        for (const Player& player : players) {
            if (player.getVictoryPoints() >= 10) {
                return player;
            }
        }
        return players[0]; // במקרה שאין מנצח, נחזיר את השחקן הראשון
    }

    void Game::printWinner() const {
        if (isGameOver()) {
            std::cout << "Winner: " << getWinner().getName() << std::endl;
        } else {
            std::cout << "No winner yet." << std::endl;
        }
    }

    Board& Game::getBoard() {
        return board;
    }

    DevelopmentCards& Game::getDevelopmentCards() {
        return devCards;
    }

    void Game::ChooseStartingPlayer() {
        currentPlayerIndex = std::rand() % players.size();
        std::cout << "Starting player: " << players[currentPlayerIndex].getName() << std::endl;
    }
}
