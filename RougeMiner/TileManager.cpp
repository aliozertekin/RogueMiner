// TileManager.cpp
#include "TileManager.h"
#include "Tiles/Air.h"
#include "Tiles/Stone.h"
#include "Tiles/Cobblestone.h"

std::map<std::string, TileBase> TileManager::tileRegistry;

void TileManager::RegisterTiles()
{
    RegisterTile(Air().ID, Air());
    RegisterTile(Stone().ID, Stone());
    RegisterTile(Cobblestone().ID, Cobblestone());
}

void TileManager::RegisterTile(std::string uniqueKey, TileBase base)
{
    tileRegistry[uniqueKey] = base;
}

TileBase* TileManager::GetTile(std::string uniqueKey)
{
    return &tileRegistry[uniqueKey];
}