#pragma once
#include "TileBase.h"

class CoalOre : public TileBase {
public:
    CoalOre() {
        textureRect = sf::IntRect(96, 32, 32, 32);
        ID = "RM_COAL_ORE";
        Name = "CoalOre";
        Description = "Coal is a hard rock which can be burned as a fossil fuel. ";
        hardness = 6;
        weight = 10;
    }
};