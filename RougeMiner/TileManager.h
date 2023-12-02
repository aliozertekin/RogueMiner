#pragma once

#include <map>
#include <string>
#include "Tiles/TileBase.h"
#include <iostream>
#include <random>
#include "Utils.h"

static std::vector<std::string> ores;

class TileManager {
public:
    static std::map<std::string, TileBase> tileRegistry;
   
    static void RegisterTiles();
    static void RegisterTile(std::string uniqueKey, TileBase base);
    static TileBase* GetTile(std::string uniqueKey);
    //Gets the probability (weight) of an Ore.
    static int GetWeight(std::string uniqueKey);
    //Registers the Added Ores (func AddOres to add ores.)
    static void RegisterOres();
    static std::vector<std::string> AddOres(std::string uniqueKey, std::vector<std::string> vector);
    //Gets a random Tile ID from the inputted vector.
    static std::string GetOreID(std::vector<std::string> ores);
    static std::vector<std::string> GetOreVector();
};