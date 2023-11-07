#include "ChunkManager.h"
#include <iostream>
std::unordered_map<int, std::unordered_map<int, Chunk>> ChunkManager::chunks;

//TO-DO Randomly generated world
void ChunkManager::InitChunks() {
	GenerateChunk(-1, -1);
	GenerateChunk(-1, 0);
	GenerateChunk(0, -1);
	GenerateChunk(0, 0);
	GenerateChunk(-2, -2);
	GenerateChunk(-2, -1);
	GenerateChunk(-1, -2);
}

void ChunkManager::GenerateChunk(int xPos, int yPos)
{
	auto chunk = std::make_shared<Chunk>(xPos, yPos);

    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
			auto tile = std::make_shared<Tile>(0, x, y, chunk.get());
            chunk->setTileAt(x, y, *tile.get());
        }
    }

    (*getChunks())[xPos][yPos] = *chunk;
}


Chunk* ChunkManager::getChunk(int x, int y)
{
	if (chunks.find(x) != chunks.end()) {
		auto& xChunks = chunks[x];
		if (xChunks.find(y) != xChunks.end()) {
			return &xChunks[y];
		}
	}
	return nullptr;
}

Chunk* ChunkManager::getChunkWorld(float x, float y)
{
	int chunkX = floor(x / 512);
	int chunkY = floor(y / 512);
	return getChunk(chunkX, chunkY);
}

void ChunkManager::setTileAt(int x, int y, Tile tile)
{
	int chunkX = floor(static_cast<float>(x) / 16);
	int chunkY = floor(static_cast<float>(y) / 16);
	Chunk* chunk = getChunk(chunkX, chunkY);
	chunk->setTileAt(x % 16, y % 16, tile);
}

Tile* ChunkManager::getTileAt(int x, int y)
{
	int chunkX = floor(static_cast<float>(x) / 16);
	int chunkY = floor(static_cast<float>(y) / 16);
	Chunk* chunk = getChunk(chunkX, chunkY);
	return chunk->getTileAt(x % 16, y % 16);
}



std::unordered_map<int, std::unordered_map<int, Chunk>>* ChunkManager::getChunks()
{
	return &chunks;
}
