#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Board.hpp"

using namespace std;
using namespace ariel;

int main()
{
    Player p1("Maria");
    Player p2("Rout");
    Player p3("Rachel");
    Game catan({p1, p2, p3});
    
    // Start of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // should print the name of the starting player
    Board& board = catan.getBoard(); // get the board of the game

    board.printBoard();
    
    // Initial placements
    p1.placeSettlement(1, board);
    p1.placeRoad(1, board);
    p2.placeSettlement(2, board);
    p2.placeRoad(2, board);
    p3.placeSettlement(3, board);
    p3.placeRoad(3, board);

    p1.placeSettlement(4, board);
    p1.placeRoad(4, board);
    p2.placeSettlement(5, board);
    p2.placeRoad(5, board);
    p3.placeSettlement(6, board);
    p3.placeRoad(6, board);

    // Simulate turns
    for (int turn = 0; turn < 30; ++turn) {
        Player& current_player = catan.getBoard().getPlayer(catan.getBoard().getPlayerTurn());
        
        current_player.rollDice(board);
        
        if (turn % 3 == 0) {
            // Every 3rd turn try to build settlements/roads/cities
            if (board.canBuildSettlement(turn % 20, current_player)) {
                current_player.placeSettlement(turn % 20, board);
            }
            if (board.canBuildRoad(turn % 70, current_player)) {
                current_player.placeRoad(turn % 70, board);
            }
            current_player.buildCity();
        }
        
        current_player.endTurn(board);
    }

    // Print final points
    p1.printPoints(); 
    p2.printPoints(); 
    p3.printPoints();

    // Determine winner
    catan.printWinner(); 

    return 0;
}
