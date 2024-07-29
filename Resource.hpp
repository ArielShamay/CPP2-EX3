#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>

namespace ariel {
    enum class Resource {
        NONE,
        WOOD,
        BRICK,
        WOOL,
        GRAIN,
        ORE,
        ROAD,        // הוספת ROAD
        SETTLEMENT,  // הוספת SETTLEMENT
        CITY         // הוספת CITY
    };

    std::string resourceToString(Resource resource); // הוספת הפונקציה להמרה למחרוזת
} // namespace ariel

#endif // RESOURCE_HPP
