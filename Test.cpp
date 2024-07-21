// Test.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tile.hpp"
#include "Edge.hpp"

using namespace ariel;

TEST_CASE("Tile functionality") {
    Tile t(Tile::FOREST, 1);
    CHECK(t.getType() == Tile::FOREST);
    CHECK(t.getNumber() == 0); // Assuming default is 0
    CHECK(t.getResource() == Resource::WOOD);
    t.setNumber(5);
    CHECK(t.getNumber() == 5);
    CHECK(t.toString() == "FOREST 5");
}

TEST_CASE("Edge functionality") {
    Edge e1(1, 1);
    Edge e2(1, 2);
    CHECK(e1.getId() == 1);
    CHECK(e1.getSubId() == 1);
    e1.setPlayerId("Player1");
    CHECK(e1.getPlayerId() == "Player1");
    e1.addNeighbor(&e2);
    CHECK(e1.getNeighbors().size() == 1);
    CHECK(e1.getNeighbors()[0] == &e2);
}
