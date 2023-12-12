#pragma once
#include "TileBase.h"

class TinOre : public TileBase {
public:
    TinOre() {
        textureID = "tin_ore";
        ID = "RM_TIN_ORE";
        Name = "TinOre";
        Description = "A silvery-coloured metal, tin is soft enough to be cut with little force.";
        hardness = 8;
    }
};