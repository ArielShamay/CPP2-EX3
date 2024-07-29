#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include <vector>
#include <cstdlib> // for std::rand

namespace ariel {

    class DevelopmentCard {
    public:
        enum class Type { KNIGHT, VICTORY_POINT, ROAD_BUILDING, YEAR_OF_PLENTY, MONOPOLY };

        DevelopmentCard(); // Default constructor
        DevelopmentCard(Type type);

        Type getType() const;
        std::string toString() const;

    private:
        Type type;
    };

    class DevelopmentCards {
    public:
        DevelopmentCards();

        DevelopmentCard drawCard();
        void addCard(const DevelopmentCard& card);

    private:
        std::vector<DevelopmentCard> deck;
    };

} // namespace ariel

#endif // DEVELOPMENTCARD_HPP
