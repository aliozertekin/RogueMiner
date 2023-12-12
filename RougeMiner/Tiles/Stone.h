#pragma once
#include "TileBase.h"

class Stone : public TileBase {
public:
    Stone() {
        textureID = "stone";
        ID = "RM_STONE";
        Name = "Stone";
        Description = "A hard stone.";
        hardness = 5;
    }
};