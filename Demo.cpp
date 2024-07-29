#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Board.hpp"

using namespace std;
using namespace ariel;

int main() {
    Player p1("Maria");
    Player p2("Rout");
    Player p3("Rachel");
    Game catan({p1, p2, p3});
    
    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // should print the name of the starting player
    Board board = catan.getBoard(); // get the board of the game

    // Initial placement of settlements and roads
    p1.placeSettlement(1, board);
    p1.placeRoad(1, board); 
    p1.placeSettlement(3, board);
    p1.placeRoad(2, board); 

    p2.placeSettlement(4, board);
    p2.placeRoad(3, board);
    p2.placeSettlement(5, board);
    p2.placeRoad(4, board); 

    p3.placeSettlement(6, board);
    p3.placeRoad(5, board);
    p3.placeSettlement(7, board);
    p3.placeRoad(6, board);

    // Game turns
    p1.rollDice(board); 
    p1.placeRoad(8, board);
    p1.endTurn(board);

    p2.rollDice(board); 
    p2.endTurn(board);

    p3.rollDice(board); 
    p3.endTurn(board);

    p1.rollDice(board); 
    p1.trade(p2, "WOOD", "BRICK", 1, 1);
    p1.endTurn(board);

    p2.rollDice(board); 
    p2.buyDevelopmentCard(catan.getDevelopmentCards());
    p2.endTurn(board);

    p3.rollDice(board); 
    p3.endTurn(board);

    // Additional moves to ensure Maria wins with 10 points
    p1.placeSettlement(8, board); 
    p1.buildCity();
    p1.placeSettlement(9, board); 
    p1.buildCity();
    p1.placeSettlement(10, board); 
    p1.buildCity();
    p1.placeSettlement(11, board); 
    p1.buildCity();

    p1.printPoints();  // Maria should have 8 points now (4 settlements and 4 cities)
    p1.buyDevelopmentCard(catan.getDevelopmentCards()); // Maria buys a development card that gives her 1 point
    p1.printPoints();  // Maria should have 9 points now
    p1.buyDevelopmentCard(catan.getDevelopmentCards()); // Maria buys another development card that gives her 1 point
    p1.printPoints();  // Maria should have 10 points now

    catan.printWinner(); // Maria should be the winner
}
