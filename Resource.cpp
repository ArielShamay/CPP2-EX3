#include "Resource.hpp"

namespace ariel {
    std::string resourceToString(Resource resource) {
        switch (resource) {
            case Resource::NONE: return "None";
            case Resource::WOOD: return "Wood";
            case Resource::BRICK: return "Brick";
            case Resource::WOOL: return "Wool";
            case Resource::GRAIN: return "Grain";
            case Resource::ORE: return "Ore";
            case Resource::ROAD: return "Road";
            case Resource::SETTLEMENT: return "Settlement";
            case Resource::CITY: return "City";
            default: return "Unknown";
        }
    }
} // namespace ariel
