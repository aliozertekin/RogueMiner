#pragma once
#include "TileBase.h"

class CopperOre : public TileBase {
public:
    CopperOre() {
        textureRect = sf::IntRect(32, 32, 32, 32);
        ID = "RM_COPPER_ORE";
        Name = "CopperOre";
        Description = "Soft, malleable, and ductile metal with very high thermal and electrical conductivity.";
        hardness = 6;
    }
};