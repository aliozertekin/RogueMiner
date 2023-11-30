#pragma once
#include "TileBase.h"

class Air : public TileBase {
public:
    Air() {
        ID = "NULL";
        Name = "Air";
        Description = "Air";
        hardness = 0;
        flags = FLAGS::INVISIBLE | FLAGS::NOCOLLISION;
    }
};