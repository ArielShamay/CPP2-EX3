#include "Board.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

namespace ariel {

    Board::Board(const Player& p1, const Player& p2, const Player& p3)
        : p1(p1), p2(p2), p3(p3), positionOfRobber(10), playerTurn(1) {
        initialize();
    }

    void Board::initialize() {
        // Initialize the tiles with all resource types
        tiles.push_back(Tile(1, Tile::FOREST, 10));
        tiles.push_back(Tile(2, Tile::HILL, 2));
        tiles.push_back(Tile(3, Tile::PASTURE, 9));
        tiles.push_back(Tile(4, Tile::FIELD, 12));
        tiles.push_back(Tile(5, Tile::HILL, 6));
        tiles.push_back(Tile(6, Tile::PASTURE, 4));
        tiles.push_back(Tile(7, Tile::HILL, 10));
        tiles.push_back(Tile(8, Tile::FIELD, 9));
        tiles.push_back(Tile(9, Tile::FOREST, 11));
        tiles.push_back(Tile(10, Tile::DESERT, 7));
        tiles.push_back(Tile(11, Tile::FOREST, 3));
        tiles.push_back(Tile(12, Tile::MOUNTAIN, 8));
        tiles.push_back(Tile(13, Tile::FOREST, 8));
        tiles.push_back(Tile(14, Tile::MOUNTAIN, 3));
        tiles.push_back(Tile(15, Tile::FIELD, 4));
        tiles.push_back(Tile(16, Tile::PASTURE, 5));
        tiles.push_back(Tile(17, Tile::HILL, 5));
        tiles.push_back(Tile(18, Tile::FIELD, 6));
        tiles.push_back(Tile(19, Tile::PASTURE, 11));

        // Initialize the edges
        for (int i = 1; i <= 72; i++) {
            edges.push_back(Edge(i));
        }

        // Initialize the vertices
        for (int i = 0; i <= 53; i++) {
            vertices.push_back(Vertex(i));
        }

        // Connect the tiles to the vertices
        tiles[0].addVertex(0, 1, 2, 3, 4, 5);
        tiles[1].addVertex(1, 6, 7, 8, 9, 2);
        tiles[2].addVertex(7, 10, 11, 12, 13, 8);
        tiles[3].addVertex(4, 3, 14, 15, 16, 17);
        tiles[4].addVertex(3, 2, 9, 18, 19, 14);
        tiles[5].addVertex(9, 8, 13, 20, 21, 18);
        tiles[6].addVertex(13, 12, 22, 23, 24, 20);
        tiles[7].addVertex(16, 15, 25, 26, 27, 28);
        tiles[8].addVertex(15, 14, 19, 29, 30, 25);
        tiles[9].addVertex(19, 18, 21, 31, 32, 29);
        tiles[10].addVertex(21, 20, 24, 33, 34, 31);
        tiles[11].addVertex(24, 23, 35, 36, 37, 33);
        tiles[12].addVertex(26, 25, 30, 40, 39, 38);
        tiles[13].addVertex(30, 29, 32, 41, 42, 40);
        tiles[14].addVertex(32, 31, 34, 43, 44, 42);
        tiles[15].addVertex(34, 33, 37, 45, 46, 44);
        tiles[16].addVertex(39, 40, 41, 49, 47, 48);
        tiles[17].addVertex(41, 42, 43, 51, 50, 49);
        tiles[18].addVertex(43, 44, 45, 53, 52, 51);

        // Connect the vertices to the edges
        vertices[0].addEdges({1, 6});
        vertices[1].addEdges({1, 2, 11});
        vertices[2].addEdges({2, 3, 10});
        vertices[3].addEdges({3, 4, 17});
        vertices[4].addEdges({4, 5, 21});
        vertices[5].addEdges({5, 6});
        vertices[6].addEdges({11, 7});
        vertices[7].addEdges({7, 8, 16});
        vertices[8].addEdges({8, 9, 15});
        vertices[9].addEdges({10, 9, 22});
        vertices[10].addEdges({16, 12});
        vertices[11].addEdges({12, 13});
        vertices[12].addEdges({13, 14, 28});
        vertices[13].addEdges({14, 15, 25});
        vertices[14].addEdges({17, 18, 24});
        vertices[15].addEdges({18, 19, 32});
        vertices[16].addEdges({19, 20, 36});
        vertices[17].addEdges({21, 20});
        vertices[18].addEdges({22, 23, 27});
        vertices[19].addEdges({23, 24, 37});
        vertices[20].addEdges({25, 26, 31});
        vertices[21].addEdges({26, 27, 40});
        vertices[22].addEdges({28, 29});
        vertices[23].addEdges({29, 30, 46});
        vertices[24].addEdges({30, 31, 43});
        vertices[25].addEdges({32, 33, 39});
        vertices[26].addEdges({33, 34, 53});
        vertices[27].addEdges({34, 35});
        vertices[28].addEdges({35, 36});
        vertices[29].addEdges({37, 38, 42});
        vertices[30].addEdges({38, 39, 50});
        vertices[31].addEdges({40, 41, 45});
        vertices[32].addEdges({41, 42, 54});
        vertices[33].addEdges({43, 44, 49});
        vertices[34].addEdges({44, 45, 57});
        vertices[35].addEdges({46, 47});
        vertices[36].addEdges({47, 48});
        vertices[37].addEdges({48, 49, 60});
        vertices[38].addEdges({53, 52});
        vertices[39].addEdges({51, 52, 66});
        vertices[40].addEdges({50, 51, 56});
        vertices[41].addEdges({55, 56, 63});
        vertices[42].addEdges({54, 55, 59});
        vertices[43].addEdges({58, 59, 67});
        vertices[44].addEdges({57, 58, 62});
        vertices[45].addEdges({61, 62, 70});
        vertices[46].addEdges({60, 61});
        vertices[47].addEdges({65, 66});
        vertices[48].addEdges({64, 65});
        vertices[49].addEdges({63, 64, 69});
        vertices[50].addEdges({68, 69});
        vertices[51].addEdges({67, 68, 72});
        vertices[52].addEdges({71, 72});
        vertices[53].addEdges({70, 71});

        // Connect the edges to the vertices
        edges[0].addVertices(0, 1);
        edges[1].addVertices(1, 2);
        edges[2].addVertices(2, 3);
        edges[3].addVertices(3, 4);
        edges[4].addVertices(4, 5);
        edges[5].addVertices(5, 0);
        edges[6].addVertices(6, 7);
        edges[7].addVertices(7, 8);
        edges[8].addVertices(8, 9);
        edges[9].addVertices(9, 2);
        edges[10].addVertices(1, 6);
        edges[11].addVertices(10, 11);
        edges[12].addVertices(11, 12);
        edges[13].addVertices(12, 13);
        edges[14].addVertices(13, 8);
        edges[15].addVertices(7, 10);
        edges[16].addVertices(3, 14);
        edges[17].addVertices(14, 15);
        edges[18].addVertices(15, 16);
        edges[19].addVertices(16, 17);
        edges[20].addVertices(17, 4);
        edges[21].addVertices(9, 18);
        edges[22].addVertices(18, 19);
        edges[23].addVertices(19, 14);
        edges[24].addVertices(13, 20);
        edges[25].addVertices(20, 21);
        edges[26].addVertices(21, 18);
        edges[27].addVertices(12, 22);
        edges[28].addVertices(22, 23);
        edges[29].addVertices(23, 24);
        edges[30].addVertices(24, 20);
        edges[31].addVertices(15, 25);
        edges[32].addVertices(25, 26);
        edges[33].addVertices(26, 27);
        edges[34].addVertices(27, 28);
        edges[35].addVertices(28, 16);
        edges[36].addVertices(19, 29);
        edges[37].addVertices(29, 30);
        edges[38].addVertices(30, 25);
        edges[39].addVertices(21, 31);
        edges[40].addVertices(31, 32);
        edges[41].addVertices(32, 29);
        edges[42].addVertices(24, 33);
        edges[43].addVertices(33, 34);
        edges[44].addVertices(34, 31);
        edges[45].addVertices(23, 35);
        edges[46].addVertices(35, 36);
        edges[47].addVertices(36, 37);
        edges[48].addVertices(37, 33);
        edges[49].addVertices(30, 40);
        edges[50].addVertices(40, 39);
        edges[51].addVertices(38, 39);
        edges[52].addVertices(26, 38);
        edges[53].addVertices(32, 42);
        edges[54].addVertices(42, 41);
        edges[55].addVertices(40, 41);
        edges[56].addVertices(34, 44);
        edges[57].addVertices(44, 43);
        edges[58].addVertices(43, 42);
        edges[59].addVertices(37, 46);
        edges[60].addVertices(46, 45);
        edges[61].addVertices(45, 44);
        edges[62].addVertices(41, 49);
        edges[63].addVertices(49, 48);
        edges[64].addVertices(48, 47);
        edges[65].addVertices(47, 39);
        edges[66].addVertices(43, 51);
        edges[67].addVertices(51, 50);
        edges[68].addVertices(50, 49);
        edges[69].addVertices(45, 53);
        edges[70].addVertices(53, 52);
        edges[71].addVertices(52, 51);
    }

    Tile& Board::getTile(int id) {
        if (id < 1 || id > static_cast<int>(tiles.size())) {
            throw std::out_of_range("Tile with given ID not found");
        }
        return tiles[id - 1];
    }

    std::vector<Tile> Board::getTiles() {
        return tiles;
    }

    Edge& Board::getEdge(int id) {
        if (id < 1 || id > static_cast<int>(edges.size())) {
            throw std::out_of_range("Edge with given ID not found");
        }
        return edges[id - 1];
    }

    Vertex& Board::getVertex(int id) {
        if (id < 0 || id >= static_cast<int>(vertices.size())) {
            throw std::out_of_range("Vertex with given ID not found");
        }
        return vertices[id];
    }

    
    void Board::printBoard() const {
        std::cout << "**************** CATAN BOARD ****************" << std::endl;

        auto printTile = [&](int id) {
            if (id < 1 || id > static_cast<int>(tiles.size())) {
                std::cout << std::setw(12) << " ";
            } else {
                std::cout << std::setw(12) << tiles[id - 1].toString();
            }
        };

        std::cout << std::setw(18); printTile(1); std::cout << std::setw(18); printTile(2); std::cout << std::setw(18); printTile(3); std::cout << std::endl;
        std::cout << std::setw(12); printTile(4); std::cout << std::setw(18); printTile(5); std::cout << std::setw(18); printTile(6); std::cout << std::setw(18); printTile(7); std::cout << std::endl;
        printTile(8); std::cout << std::setw(18); printTile(9); std::cout << std::setw(18); printTile(10); std::cout << std::setw(18); printTile(11); std::cout << std::setw(18); printTile(12); std::cout << std::endl;
        std::cout << std::setw(12); printTile(13); std::cout << std::setw(18); printTile(14); std::cout << std::setw(18); printTile(15); std::cout << std::setw(18); printTile(16); std::cout << std::endl;
        std::cout << std::setw(18); printTile(17); std::cout << std::setw(18); printTile(18); std::cout << std::setw(18); printTile(19); std::cout << std::endl;

        std::cout << "**********************************************" << std::endl;
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

//    const Player& Board::getPlayer(int id) const {
//         if (id == 1) {
//             return p1;
//         } else if (id == 2) {
//             return p2;
//         } else if (id == 3) {
//             return p3;
//         } else {
//             throw std::out_of_range("Invalid player id");
//         }
//     }
    

    Player& Board::getPlayer(int id) {
        if (id == 1) {
            return const_cast<Player&>(p1);
        } else if (id == 2) {
            return const_cast<Player&>(p2);
        } else if (id == 3) {
            return const_cast<Player&>(p3);
        } else {
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
            if (edges[edge - 1].getPlayerId() == player.getName()) {
                return true;
            }
        }
        std::cout << "Player does not have a road adjacent to this vertex" << std::endl;
        return false;
    }
bool Board::canBuildRoad(int edge, Player& player) {
    if (edge < 1 || static_cast<size_t>(edge) > edges.size()) {
        std::cout << "Invalid edge ID" << std::endl;
        return false;
    }
    Edge& e = getEdge(edge);
    if (!e.getPlayerId().empty()) {
        std::cout << "Edge already has a road" << std::endl;
        return false;
    }
    for (int vertexId : e.getVertices()) { // Assuming getVertices() returns a collection of int
        Vertex& vertex = getVertex(vertexId); // Use vertexId directly
        if (vertex.getPlayerId() == player.getName()) {
            return true;
        }
    }
    std::cout << "Player does not have a settlement or city adjacent to this edge" << std::endl;
    return false;
}
 }
