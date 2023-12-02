#pragma once
#include "TileBase.h"

class TinOre : public TileBase {
public:
    TinOre() {
        textureRect = sf::IntRect(64, 32, 32, 32);
        ID = "RM_TIN_ORE";
        Name = "TinOre";
        Description = "A silvery-coloured metal, tin is soft enough to be cut with little force. Maybe you can alloy this.";
        hardness = 8;
        weight = 5;
    }
};