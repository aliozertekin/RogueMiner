#pragma once
#include "TileBase.h"

class CoalOre : public TileBase {
public:
    CoalOre() {
        textureID = "coal_ore";
        ID = "RM_COAL_ORE";
        Name = "CoalOre";
        Description = "A hard rock which can be burned as a fossil fuel.";
        hardness = 6;
    }
};