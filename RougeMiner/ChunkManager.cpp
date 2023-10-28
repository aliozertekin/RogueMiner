#include "ChunkManager.h"

std::unordered_map<int, std::unordered_map<int, Chunk>> ChunkManager::chunks;

//TO-DO Randomly generated world
void ChunkManager::InitChunks() {
	GenerateChunk(-1, -1);
	GenerateChunk(-1, 0);
	GenerateChunk(0, -1);
	GenerateChunk(0, 0);
}

void ChunkManager::GenerateChunk(int xPos, int yPos)
{
	Chunk chunk(xPos, yPos);

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			Tile tile(0, x, y, &chunk);
			chunk.setTileAt(x, y, tile);
		}
	}

	chunks[xPos][yPos] = chunk;
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

std::unordered_map<int, std::unordered_map<int, Chunk>>* ChunkManager::getChunks()
{
	return &chunks;
}
