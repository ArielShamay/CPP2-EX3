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
    
    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // should print the name of the starting player
    Board board = catan.getBoard(); // get the board of the game

    p1.placeSettlement(5, board);
    p1.placeRoad(1, board);  // example edge 1
    p1.placeSettlement(6, board);
    p1.placeRoad(2, board);  // example edge 2

    p2.placeSettlement(4, board);
    p2.placeRoad(3, board);  // example edge 3
    try
    {
        p3.placeSettlement(4, board); // p3 tries to place a settlement in the same location as p2
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    p2.placeSettlement(7, board);
    p2.placeRoad(4, board);  // example edge 4

    p3.placeSettlement(8, board);
    p3.placeRoad(5, board);  // example edge 5
    p3.placeSettlement(9, board);
    p3.placeRoad(6, board);  // example edge 6

    // p1 has wood, bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    p1.rollDice(board); // Lets say it prints 4. Then, p2 gets ore from the mountains.
    p1.placeRoad(7, board); // p1 continues to build a road.
    p1.endTurn(board);      // p1 ends his turn.

    p2.rollDice(board); // Lets say it prints 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.endTurn(board);  // p2 ends his turn.

    p3.rollDice(board); // Lets say it prints 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    p3.endTurn(board);  // p3 ends his turn.

    try
    {
        p2.rollDice(board); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    p1.rollDice(board);           // Lets say it prints 6. Then, p1 gets bricks from the hills.
    p1.trade(p2, "WOOD", "BRICK", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    p1.endTurn(board);            // p1 ends his turn.

    p2.rollDice(board);           // Lets say it prints 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.buyDevelopmentCard(catan.getDevelopmentCards()); // p2 buys a development card. Lets say it is a bonus points card.
    p2.endTurn(board);            // p2 ends his turn.

    p1.printPoints(); // p1 has 2 points because it has two settlements.
    p2.printPoints(); // p2 has 3 points because it has two settlements and a bonus points card.
    p3.printPoints(); // p3 has 2 points because it has two settlements.

    catan.printWinner(); // Should print None because no player reached 10 points.
}
