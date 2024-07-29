#include "Board.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Resource.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <stdexcept>

namespace ariel {
    Board::Board(const Player& p1, const Player& p2,const Player& p3)
        : p1(p1), p2(p2), p3(p3), positionOfRobber(0), playerTurn(1) {
        initialize();
    }

   void Board::initialize() {
    // Initialize the tiles with proper resources and unique identifiers
    tileMap.insert({1, Tile(Tile::Type::FOREST, 1)});
    tileMap.insert({2, Tile(Tile::Type::HILL, 2)});
    tileMap.insert({3, Tile(Tile::Type::PASTURE, 3)});
    tileMap.insert({4, Tile(Tile::Type::FIELD, 4)});
    tileMap.insert({5, Tile(Tile::Type::MOUNTAIN, 5)});
    tileMap.insert({6, Tile(Tile::Type::DESERT, 6)});

    // Repeat the resources to cover the whole board appropriately
    tileMap.insert({7, Tile(Tile::Type::FOREST, 7)});
    tileMap.insert({8, Tile(Tile::Type::HILL, 8)});
    tileMap.insert({9, Tile(Tile::Type::PASTURE, 9)});
    tileMap.insert({10, Tile(Tile::Type::FIELD, 10)});
    tileMap.insert({11, Tile(Tile::Type::MOUNTAIN, 11)});
    tileMap.insert({12, Tile(Tile::Type::DESERT, 12)});
    tileMap.insert({13, Tile(Tile::Type::FOREST, 13)});
    tileMap.insert({14, Tile(Tile::Type::HILL, 14)});
    tileMap.insert({15, Tile(Tile::Type::PASTURE, 15)});
    tileMap.insert({16, Tile(Tile::Type::FIELD, 16)});
    tileMap.insert({17, Tile(Tile::Type::MOUNTAIN, 17)});
    tileMap.insert({18, Tile(Tile::Type::FOREST, 18)});
    tileMap.insert({19, Tile(Tile::Type::HILL, 19)});

    // Initialize the edges
    for (int i = 1; i <= 72; i++) {
        edges.push_back(Edge(i, 0));
    }

    // Initialize the vertices
    for (int i = 0; i <= 53; i++) {
        vertices.push_back(Vertex(i));
    }

    // Connect vertices to tiles
    // Here, vertices are manually connected to tiles for simplicity
    // This part should reflect the actual game board design
    tileMap[1].setVertices({0, 1, 2, 3, 4, 5});
    tileMap[2].setVertices({3, 4, 5, 6, 7, 8});
    tileMap[3].setVertices({6, 7, 8, 9, 10, 11});
    tileMap[4].setVertices({9, 10, 11, 12, 13, 14});
    tileMap[5].setVertices({12, 13, 14, 15, 16, 17});
    tileMap[6].setVertices({15, 16, 17, 18, 19, 20});
    tileMap[7].setVertices({18, 19, 20, 21, 22, 23});
    tileMap[8].setVertices({21, 22, 23, 24, 25, 26});
    tileMap[9].setVertices({24, 25, 26, 27, 28, 29});
    tileMap[10].setVertices({27, 28, 29, 30, 31, 32});
    tileMap[11].setVertices({30, 31, 32, 33, 34, 35});
    tileMap[12].setVertices({33, 34, 35, 36, 37, 38});
    tileMap[13].setVertices({36, 37, 38, 39, 40, 41});
    tileMap[14].setVertices({39, 40, 41, 42, 43, 44});
    tileMap[15].setVertices({42, 43, 44, 45, 46, 47});
    tileMap[16].setVertices({45, 46, 47, 48, 49, 50});
    tileMap[17].setVertices({48, 49, 50, 51, 52, 53});
    tileMap[18].setVertices({51, 52, 53, 54, 55, 56});
    tileMap[19].setVertices({54, 55, 56, 57, 58, 59});
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
