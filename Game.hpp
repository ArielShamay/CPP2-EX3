#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "DevelopmentCard.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

namespace ariel {
    class Game {
    Board board; // Declare board first
    bool gameOver; 
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

        void printWinner() const;
        Board& getBoard();  // שינוי כדי להחזיר reference
        DevelopmentCards& getDevelopmentCards(); 
        void ChooseStartingPlayer();

    private:
        Board board;
        std::vector<Player> players;
        int currentPlayerIndex;
        bool gameOver;
        DevelopmentCards devCards;
    };
} // namespace ariel

#endif // GAME_HPP
