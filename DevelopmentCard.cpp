#include "DevelopmentCard.hpp"
#include <iostream>
namespace ariel {

    DevelopmentCard::DevelopmentCard() {
        int randomType = std::rand() % 5; // Generate a random number between 0 and 4
        switch (randomType) {
            case 0: type = Type::KNIGHT; break;
            case 1: type = Type::VICTORY_POINT; break;
            case 2: type = Type::ROAD_BUILDING; break;
            case 3: type = Type::YEAR_OF_PLENTY; break;
            case 4: type = Type::MONOPOLY; break;
            default: type = Type::KNIGHT; break; // Default to KNIGHT if something goes wrong
        }
    }

    DevelopmentCard::DevelopmentCard(Type type) : type(type) {}

    DevelopmentCard::Type DevelopmentCard::getType() const {
        return type;
    }

    std::string DevelopmentCard::toString() const {
        switch (type) {
            case Type::KNIGHT: return "Knight";
            case Type::VICTORY_POINT: return "Victory Point";
            case Type::ROAD_BUILDING: return "Road Building";
            case Type::YEAR_OF_PLENTY: return "Year of Plenty";
            case Type::MONOPOLY: return "Monopoly";
            default: return "Unknown";
        }
    }

    DevelopmentCards::DevelopmentCards() {
        // Initialize the deck with some cards
        deck.push_back(DevelopmentCard(DevelopmentCard::Type::KNIGHT));
        deck.push_back(DevelopmentCard(DevelopmentCard::Type::VICTORY_POINT));
        deck.push_back(DevelopmentCard(DevelopmentCard::Type::ROAD_BUILDING));
        deck.push_back(DevelopmentCard(DevelopmentCard::Type::YEAR_OF_PLENTY));
        deck.push_back(DevelopmentCard(DevelopmentCard::Type::MONOPOLY));
        // Add more cards as needed
    }

    DevelopmentCard DevelopmentCards::drawCard() {
        if (deck.empty()) {
            throw std::out_of_range("No more development cards in the deck");
        }
        int randomIndex = std::rand() % deck.size();
        DevelopmentCard card = deck[randomIndex];
        deck.erase(deck.begin() + randomIndex);
        return card;
    }

    void DevelopmentCards::addCard(const DevelopmentCard& card) {
        deck.push_back(card);
    }

} // namespace ariel
