// Name - Ariel Shamay
// CP_EX_3
// Mail - Arielsh49@gmail.com


#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "Board.hpp"
#include "Player.hpp"

class Catan {
    private:
        Board board; // The game board
    public:
        // Constructor
        Catan(Player& p1, Player& p2, Player& p3);

        // Getters
        Board& getBoard();
};

#endif // CATAN_HPP