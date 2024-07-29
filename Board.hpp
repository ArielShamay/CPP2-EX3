#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include "Edge.hpp"
#include "Vertex.hpp"
#include "Player.hpp"
#include "Tile.hpp"

namespace ariel {
    class Board {
   
     public:
        Board(const Player& p1, const Player& p2, const Player& p3);

        void initialize();
        Tile& getTile(int id);
        std::vector<Tile> getTiles() const;
        bool tileExists(int id) const;
        Edge& getEdge(int id);
        Vertex& getVertex(int id);
        void addTile(const Tile& tile);
        std::string toString() const;

        void buildRoad(int edge, Player& player);
        void buildSettlement(int vertex, Player& player);
        void buildCity(int vertex, Player& player);
        void shareResources(size_t dice);
        int getPlayerTurn() const;
        void nextTurn();
        void reduceHalfResourcesFromPlayers();
        void setRobber(int position);
        int getRobber() const;
        const Player& getPlayer(int id) const;
        Player& getPlayer(int id); 
        void monopolyAction(size_t res, Player& player);
        void checkVictoryPoints();
        void finishGame();
        bool canBuildSettlement(int vertex, Player& player);
        bool canBuildRoad(int edge, Player& player);
        void printBoard() const;

    private:
        const Player& p1;
        const Player& p2;
        const Player& p3;
        int positionOfRobber;
        int playerTurn;
        std::map<int, Tile> tileMap;
        std::vector<Edge> edges;
        std::vector<Vertex> vertices;
    };
} // namespace ariel

#endif // BOARD_HPP
