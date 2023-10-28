#pragma once
#include <SFML\Graphics.hpp>
#include "Types/Chunk.h"
#include "Types\Tile.h"
#include <unordered_map>

class ChunkManager {
public:
	static void InitChunks();
	static void GenerateChunk(int xPos, int yPos);

	static Chunk* getChunk(int x, int y);
	static std::unordered_map<int, std::unordered_map<int, Chunk>>* getChunks();
private:
	static std::unordered_map<int, std::unordered_map<int, Chunk>> chunks;
};