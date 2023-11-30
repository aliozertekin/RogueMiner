#pragma once
#include "TileBase.h"

class Cobblestone : public TileBase {
public:
    Cobblestone() {
        textureRect = sf::IntRect(32, 0, 32, 32);
        ID = "RM_COBBLESTONE";
        Name = "Cobblestone";
        Description = "A semi-hard stone.";
        hardness = 4;
    }
};