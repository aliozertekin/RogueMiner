#pragma once
#include "TileBase.h"

class Stone : public TileBase {
public:
    Stone() {
        textureRect = sf::IntRect(0, 0, 32, 32);
        ID = "RM_STONE";
        Name = "Stone";
        Description = "A hard stone.";
        hardness = 5;
        weight = 0;
    }
};