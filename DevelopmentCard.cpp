// mail - Arielsh49@gmail.com
// Author - Ariel Shamay

#include "DevelopmentCard.hpp"

// Constructor
DevelopmentCard::DevelopmentCard() 
    : knights(0), victoryPoints(0), roadBuilding(0), yearOfPlenty(0), monopoly(0),openKnights(0), biggestArmy(false) {}

// Buy card
void DevelopmentCard::buyCard() 
{
    bool bought = false;
    while(!bought){
        size_t dice1 = rand() % 5 + 1;
        
        switch (dice1)
        {
        case 1:
            if(knights < MAX_KNIGHTS){
                addKnight();
                cout << "You bought a Knight card" << endl;
                bought = true;
            }
            break;
        case 2:
            if (victoryPoints < MAX_VICTORY_POINTS) {
                addVictoryPoint();
                cout << "You bought a Victory Point card" << endl;
                bought = true;
            }
            break;
        case 3:
            addRoadBuilding();
            cout << "You bought a Road Building card" << endl;
            bought = true;
            break;
        case 4:
            addYearOfPlenty();
            cout << "You bought a Year of Plenty card" << endl;
            bought = true;
            break;
        case 5:
            addMonopoly();
            cout << "You bought a Monopoly card" << endl;
            bought = true;
            break;
        default:
            break;
        }
    }
}

// Add cards
void DevelopmentCard::addOpenKnight() {
    openKnights++;
}

void DevelopmentCard::addKnight() {
    knights++;
}

void DevelopmentCard::addVictoryPoint() {
    victoryPoints++;
}

void DevelopmentCard::addRoadBuilding() {
    roadBuilding++;
}

void DevelopmentCard::addYearOfPlenty() {
    yearOfPlenty++;
}

void DevelopmentCard::addMonopoly() {
    monopoly++;
}

// Remove cards
void DevelopmentCard::removeOpenKnight() {
    if (openKnights > 0) openKnights--;
}

void DevelopmentCard::removeKnight() {
    if (knights > 0) knights--;
}

void DevelopmentCard::removeVictoryPoint() {
    if (victoryPoints > 0) victoryPoints--;
}

void DevelopmentCard::removeRoadBuilding() {
    if (roadBuilding > 0) roadBuilding--;
}

void DevelopmentCard::removeYearOfPlenty() {
    if (yearOfPlenty > 0) yearOfPlenty--;
}

void DevelopmentCard::removeMonopoly() {
    if (monopoly > 0) monopoly--;
}

// Get card counts
size_t DevelopmentCard::getKnight() const {
    return knights;
}

size_t DevelopmentCard::getVictoryPoint() const {
    return victoryPoints;
}

size_t DevelopmentCard::getRoadBuilding() const {
    return roadBuilding;
}

size_t DevelopmentCard::getYearOfPlenty() const {
    return yearOfPlenty;
}

size_t DevelopmentCard::getMonopoly() const {
    return monopoly;
}

size_t DevelopmentCard::getOpenKnight() const {
    return openKnights;
}

void DevelopmentCard::setBiggestArmy(bool biggestArmy) {
    this->biggestArmy = biggestArmy;
}

// Count total cards
size_t DevelopmentCard::countCards() const {
    return knights + victoryPoints + roadBuilding + yearOfPlenty + monopoly;
}

// Print status
void DevelopmentCard::status() const {
    std::cout << "\tDevelopment Cards Status:" << std::endl;
    std::cout << "\t\tKnights: " << knights << std::endl;
    std::cout << "\t\tVictory Points: " << victoryPoints << std::endl;
    std::cout << "\t\tRoad Building: " << roadBuilding << std::endl;
    std::cout << "\t\tYear of Plenty: " << yearOfPlenty << std::endl;
    std::cout << "\t\tMonopoly: " << monopoly << std::endl;
    std::cout << "\t\tBiggest Army: " << (biggestArmy ? "Yes" : "No") << std::endl;
}

// Get victory points
size_t DevelopmentCard::getPoints() const {
    size_t points = 0;
    points += victoryPoints;
    if (biggestArmy) points += 2;
    return points;
}