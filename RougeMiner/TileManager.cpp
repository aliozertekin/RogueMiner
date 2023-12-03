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

    RegisterOres();
}

void TileManager::RegisterTile(std::string uniqueKey, TileBase base)
{
    tileRegistry[uniqueKey] = base;
}

TileBase* TileManager::GetTile(std::string uniqueKey)
{
    return &tileRegistry[uniqueKey];
}

void TileManager::RegisterOres()
{
    std::map<std::string, OreDefinition> oreRegistry;

    oreRegistry[CopperOre().ID] = OreDefinition(1.5);
    oreRegistry[TinOre().ID] = OreDefinition(0.7);
    oreRegistry[CoalOre().ID] = OreDefinition(1.0);

    Utils::RegisterOres(oreRegistry);
}

TileBase* TileManager::GetRandomOre()
{
    return GetTile(Utils::GetRandomOre());
}
