// TileManager.cpp
#include "TileManager.h"
#include "Tiles/Air.h"
#include "Tiles/Stone.h"
#include "Tiles/Cobblestone.h"
#include "Tiles/CopperOre.h"
#include "Tiles/TinOre.h"
#include "Tiles/CoalOre.h"

std::map<std::string, TileBase> TileManager::tileRegistry;

void TileManager::RegisterTiles()
{
    RegisterTile(Air().ID, Air());
    RegisterTile(Stone().ID, Stone());
    RegisterTile(Cobblestone().ID, Cobblestone());
    RegisterTile(CopperOre().ID, CopperOre());
    RegisterTile(TinOre().ID, TinOre());
    RegisterTile(CoalOre().ID, CoalOre());
}

void TileManager::RegisterTile(std::string uniqueKey, TileBase base)
{
    tileRegistry[uniqueKey] = base;
}

TileBase* TileManager::GetTile(std::string uniqueKey)
{
    return &tileRegistry[uniqueKey];
}

int TileManager::GetWeight(std::string uniqueKey)
{
    return tileRegistry[uniqueKey].weight;
}

std::vector<std::string> TileManager::AddOres(std::string uniqueKey, std::vector<std::string> vector)
{
    for (int i = 0; i < GetWeight(uniqueKey); ++i) 
        vector.push_back(tileRegistry[uniqueKey].ID);
    return vector;
}

void TileManager::RegisterOres()
{
    std::vector<std::string> Ores;

    Ores = AddOres("RM_TIN_ORE", Ores);
    Ores = AddOres("RM_COPPER_ORE", Ores);
    // Ores = AddOres("RM_COAL_ORE", Ores);


    ores = Ores;
}

std::string TileManager::GetOreID(std::vector<std::string> ores)
{

    int rand = static_cast<int>((std::rand() * RAND_MAX  + std::rand()) % ores.size());
    if (rand <= 0) { rand = 1; }
    else if (rand >= ores.size()) { rand = ores.size() - 1; }
    //#ifdef DEBUG 
        std::cout << ores[rand] << "  " << rand << std::endl;
    //#endif
    return ores[rand];
   
}

std::vector<std::string> TileManager::GetOreVector() {
    return ores;
}
