#pragma once

#include <map>
#include <string>
#include <iostream>
#include <random>
#include "Tiles/TileBase.h"
#include "Utils.h"
#include "Types/OreDefinition.h"
#include "TextureManager.h"

static std::vector<std::string> ores;

class TileManager {
public:
    static std::map<std::string, TileBase> tileRegistry;
   
    static void RegisterTiles();
    static void RegisterTile(std::string uniqueKey, TileBase base);
    static TileBase* GetTile(std::string uniqueKey);

    static void RegisterOres();
    static TileBase* GetRandomOre();
};