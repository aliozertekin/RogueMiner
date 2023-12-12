#pragma once
#include "TileBase.h"

class Cobblestone : public TileBase {
public:
    Cobblestone() {
        textureID = "cobblestone";
        ID = "RM_COBBLESTONE";
        Name = "Cobblestone";
        Description = "A semi-hard stone.";
        hardness = 4;
    }
};