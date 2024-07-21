#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>

namespace ariel {
    class DevelopmentCard {
    public:
        enum class Type { KNIGHT, VICTORY_POINT, ROAD_BUILDING, YEAR_OF_PLENTY, MONOPOLY };

        DevelopmentCard(Type type);

        Type getType() const;
        std::string toString() const;

    private:
        Type type;
    };
} // namespace ariel

#endif // DEVELOPMENT_CARD_HPP
