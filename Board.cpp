#include "Board.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Resource.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <stdexcept>
#include <iomanip> // For std::setw

namespace ariel {
    Board::Board(const Player& p1, const Player& p2,const Player& p3)
        : p1(p1), p2(p2), p3(p3), positionOfRobber(0), playerTurn(1) {
        initialize();
    }
void Board::initialize() {
    // Initialize the tiles with all resource types
    tileMap.insert({1, Tile(Tile::Type::FOREST, 1)});
    tileMap.insert({2, Tile(Tile::Type::HILL, 2)});
    tileMap.insert({3, Tile(Tile::Type::PASTURE, 3)});
    tileMap.insert({4, Tile(Tile::Type::FIELD, 4)});
    tileMap.insert({5, Tile(Tile::Type::MOUNTAIN, 5)});
    tileMap.insert({6, Tile(Tile::Type::DESERT, 6)});
    tileMap.insert({7, Tile(Tile::Type::FOREST, 7)});
    tileMap.insert({8, Tile(Tile::Type::HILL, 8)});
    tileMap.insert({9, Tile(Tile::Type::PASTURE, 9)});
    tileMap.insert({10, Tile(Tile::Type::FIELD, 10)});
    tileMap.insert({11, Tile(Tile::Type::MOUNTAIN, 11)});
    tileMap.insert({12, Tile(Tile::Type::FOREST, 12)});
    tileMap.insert({13, Tile(Tile::Type::HILL, 13)});
    tileMap.insert({14, Tile(Tile::Type::PASTURE, 14)});
    tileMap.insert({15, Tile(Tile::Type::FIELD, 15)});
    tileMap.insert({16, Tile(Tile::Type::MOUNTAIN, 16)});
    tileMap.insert({17, Tile(Tile::Type::FOREST, 17)});
    tileMap.insert({18, Tile(Tile::Type::HILL, 18)});
    tileMap.insert({19, Tile(Tile::Type::PASTURE, 19)});

    // Set vertices for each tile
    tileMap[1].setVertices({1, 2, 3, 4, 5, 6});
    tileMap[2].setVertices({7, 8, 9, 10, 11, 12});
    tileMap[3].setVertices({13, 14, 15, 16, 17, 18});
    tileMap[4].setVertices({19, 20, 21, 22, 23, 24});
    tileMap[5].setVertices({25, 26, 27, 28, 29, 30});
    tileMap[6].setVertices({31, 32, 33, 34, 35, 36});
    tileMap[7].setVertices({37, 38, 39, 40, 41, 42});
    tileMap[8].setVertices({43, 44, 45, 46, 47, 48});
    tileMap[9].setVertices({49, 50, 51, 52, 53, 54});
    tileMap[10].setVertices({55, 56, 57, 58, 59, 60});
    tileMap[11].setVertices({61, 62, 63, 64, 65, 66});
    tileMap[12].setVertices({67, 68, 69, 70, 71, 72});
    tileMap[13].setVertices({73, 74, 75, 76, 77, 78});
    tileMap[14].setVertices({79, 80, 81, 82, 83, 84});
    tileMap[15].setVertices({85, 86, 87, 88, 89, 90});
    tileMap[16].setVertices({91, 92, 93, 94, 95, 96});
    tileMap[17].setVertices({97, 98, 99, 100, 101, 102});
    tileMap[18].setVertices({103, 104, 105, 106, 107, 108});
    tileMap[19].setVertices({109, 110, 111, 112, 113, 114});

    // Initialize the edges
    for (int i = 1; i <= 72; i++) {
        edges.push_back(Edge(i, 0));
    }

    // Initialize the vertices
    for (int i = 0; i <= 53; i++) {
        vertices.push_back(Vertex(i));
    }
}

    Tile& Board::getTile(int id) {
        if (tileExists(id)) {
            return tileMap.at(id);
        }
        throw std::out_of_range("Tile with given ID not found");
    }

    std::vector<Tile> Board::getTiles() const {
        std::vector<Tile> tileVector;
        for (const auto& pair : tileMap) {
            tileVector.push_back(pair.second);
        }
        return tileVector;
    }

    bool Board::tileExists(int id) const {
        return tileMap.find(id) != tileMap.end();
    }

    Edge& Board::getEdge(int id) {
        for (auto& edge : edges) {
            if (edge.getId() == id) {
                return edge;
            }
        }
        throw std::out_of_range("Edge with given ID not found");
    }

void Board::printBoard() const {
    std::cout << "**************** CATAN BOARD ****************" << std::endl;
    std::cout << "Tile ID  |  Resource  |  Number  |  Vertices  |  Edges" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    for (const auto& tilePair : tileMap) {
        const Tile& tile = tilePair.second;
        std::cout << std::setw(8) << tile.getId() << " | ";
        std::cout << std::setw(10) << tile.toString() << " | ";
        std::cout << std::setw(7) << tile.getNumber() << " | ";
        const std::vector<int>& vertices = tile.getVertices();
        for (int vertex : vertices) {
            std::cout << vertex << " ";
        }
        std::cout << "| ";
        const std::vector<int>& edges = tile.getEdges();
        for (int edge : edges) {
            std::cout << edge << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "**********************************************" << std::endl;
}


    Vertex& Board::getVertex(int id) {
        for (auto& vertex : vertices) {
            if (vertex.getId() == id) {
                return vertex;
            }
        }
        throw std::out_of_range("Vertex with given ID not found");
    }

    void Board::addTile(const Tile& tile) {
        tileMap.insert({tile.getId(), tile});
    }

    std::string Board::toString() const {
        std::ostringstream oss;
        for (const auto& tile : tileMap) {
            oss << tile.second.toString() << "\n";
        }
        return oss.str();
    }

    void Board::buildRoad(int edge, Player& player) {
        edges[edge - 1].setPlayerId(player.getName());
        player.addResource(Resource::ROAD, 1);
        std::cout << "Road built at edge: " << edge << std::endl;
    }

    void Board::buildSettlement(int vertex, Player& player) {
        Vertex& v = getVertex(vertex);
        v.setPlayerId(player.getName());
        v.setCityType(Vertex::CityType::SETTLEMENT);
        player.addResource(Resource::SETTLEMENT, 1);
        std::cout << "Settlement built at vertex: " << vertex << std::endl;
    }

    void Board::buildCity(int vertex, Player& player) {
        Vertex& v = getVertex(vertex);
        v.setCityType(Vertex::CityType::CITY);
        player.addResource(Resource::CITY, 1);
        std::cout << "City built at vertex: " << vertex << std::endl;
    }

    void Board::shareResources(size_t dice) {
        std::cout << "Sharing resources: " << std::endl;
        for (Tile& tile : getTiles()) {
            if (tile.getNumber() == static_cast<int>(dice) && getRobber() != tile.getId()) {      
                for (int vertexId : tile.getVertices()) {
                    Vertex& vertex = getVertex(vertexId);
                    if (vertex.getCityType() != Vertex::CityType::NONE) {
                        Player& player = getPlayer(vertex.getId());
                        player.addResource(tile.getResource(), (vertex.getCityType() == Vertex::CityType::CITY) ? 2 : 1);
                        std::cout << "\tPlayer " << player.getName() << " got " << ((vertex.getCityType() == Vertex::CityType::CITY) ? 2 : 1) << " " << resourceToString(tile.getResource()) << std::endl;
                    }
                }
            }
        }
    }

    int Board::getPlayerTurn() const {
        return playerTurn;
    }

    void Board::nextTurn() {
        checkVictoryPoints();
        playerTurn = (playerTurn % 3) + 1;
        getPlayer(playerTurn).setAlreadyRolled(false);
    }

    void Board::reduceHalfResourcesFromPlayers() {
        std::cout << "Reducing half resources from players who have more than 7 resources" << std::endl;
        for (int i = 1; i <= 3; i++) {
            Player& player = getPlayer(i);
            player.reduceHalfResources();
        }
    }

    void Board::setRobber(int position) {
        if (position < 1 || position > 19) {
            std::cout << "Invalid position tile for robber" << std::endl;
            return;
        }
        positionOfRobber = position;
        std::cout << "Robber moved to tile id: " << position << std::endl;
    }

    int Board::getRobber() const {
        return positionOfRobber;
    }

    const Player& Board::getPlayer(int id) const {
        if (id == 1) {
            return p1;
        } else if (id == 2) {
            return p2;
        } else if (id == 3) {
            return p3;
        } else {
            std::cout << "Invalid player id" << std::endl;
            throw std::out_of_range("Invalid player id");
        }
    }

    Player& Board::getPlayer(int id) {
        if (id == 1) {
            return const_cast<Player&>(p1);
        } else if (id == 2) {
            return const_cast<Player&>(p2);
        } else if (id == 3) {
            return const_cast<Player&>(p3);
        } else {
            std::cout << "Invalid player id" << std::endl;
            throw std::out_of_range("Invalid player id");
        }
    }

    void Board::monopolyAction(size_t res, Player& player) {
        std::cout << "Monopoly action: " << std::endl;
        for (int i = 1; i <= 3; i++) {
            Player& current_player = getPlayer(i);
            if (current_player.getName() == player.getName()) {
                continue;
            }
            int amount = current_player.getResourceCount(static_cast<Resource>(res));
            current_player.removeResource(static_cast<Resource>(res), amount);
            player.addResource(static_cast<Resource>(res), amount);
            std::cout << "\tPlayer " << player.getName() << " got " << amount << " " << resourceToString(static_cast<Resource>(res)) << " from player " << current_player.getName() << std::endl;
        }
    }

    void Board::checkVictoryPoints() {
        for (int i = 1; i <= 3; i++) {
            Player& player = getPlayer(i);
            if (player.getVictoryPoints() >= 10) {
                std::cout << "Player " << player.getName() << " won the game" << std::endl;
                std::exit(0);
            }
        }
    }

    void Board::finishGame() {
        std::exit(0);
    }

    bool Board::canBuildSettlement(int vertex, Player& player) {
        if (vertex < 0 || static_cast<size_t>(vertex) >= vertices.size()) {
            std::cout << "Invalid vertex ID" << std::endl;
            return false;
        }
        Vertex& v = getVertex(vertex);
        if (v.getCityType() != Vertex::CityType::NONE) {
            std::cout << "Vertex already has a building" << std::endl;
            return false;
        }
        for (auto& edge : v.getEdges()) {
            if (edges[edge].getPlayerId() == player.getName()) {
                return true;
            }
        }
        std::cout << "Player does not have a road adjacent to this vertex" << std::endl;
        return false;
    }

    bool Board::canBuildRoad(int edge, Player& player) {
        if (edge < 0 || static_cast<size_t>(edge) >= edges.size()) {
            std::cout << "Invalid edge ID" << std::endl;
            return false;
        }
        Edge& e = getEdge(edge);
        if (e.getPlayerId() != "") {
            std::cout << "Edge already has a road" << std::endl;
            return false;
        }
        for (auto* vertexPtr : e.getVertices()) { // Assuming e.getVertices() returns a vector of Vertex pointers
            if (vertexPtr != nullptr) { // Always a good idea to check for nullptr
                Vertex& vertex = *vertexPtr; // Dereference the pointer to get the Vertex object
                if (vertex.getPlayerId() == player.getName()) {
                    return true;
                }
            }
        }
        std::cout << "Player does not have a settlement or city adjacent to this edge" << std::endl;
        return false;
    }
}
