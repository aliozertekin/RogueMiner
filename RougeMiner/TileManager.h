#pragma once

#include <map>
#include <string>
#include "Tiles/TileBase.h"

class TileManager {
public:
    static std::map<std::string, TileBase> tileRegistry;

    static void RegisterTiles();
    static void RegisterTile(std::string uniqueKey, TileBase base);
    static TileBase* GetTile(std::string uniqueKey);
};