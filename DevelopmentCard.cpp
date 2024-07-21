#include "DevelopmentCard.hpp"

namespace ariel {
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
} // namespace ariel
