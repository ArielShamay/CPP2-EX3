#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"
#include <vector>

namespace ariel {
    class Game {
    public:
        Game(const std::vector<Player>& players);

        void start();
        void playTurn(Player& player);
        void rollDice(Player& player);
        void buildSettlement(Player& player);
        void buildCity(Player& player);
        void buildRoad(Player& player);
        void buyDevelopmentCard(Player& player);
        void endTurn(Player& player);

        bool isGameOver() const;
        Player getWinner() const;

        void printWinner() const; // הוספת הפונקציה printWinner
        Board getBoard() const; // הוספת הפונקציה getBoard

    private:
        Board board;
        std::vector<Player> players;
        int currentPlayerIndex;
        bool gameOver;
    };
} // namespace ariel

#endif // GAME_HPP
