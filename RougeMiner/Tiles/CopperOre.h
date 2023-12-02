#pragma once
#include "TileBase.h"

class CopperOre : public TileBase {
public:
    CopperOre() {
        textureRect = sf::IntRect(32, 32, 32, 32);
        ID = "RM_COPPER_ORE";
        Name = "CopperOre";
        Description = "It is a soft, malleable, and ductile metal with very high thermal and electrical conductivity. Maybe you can alloy this.";
        hardness = 6;
        weight = 15;
    }
};