#pragma once
#include <SFML\Graphics.hpp>
#include "Types/Chunk.h"
#include "Types\Tile.h"
#include "Entities/Player.h"
#include <unordered_map>

class ChunkManager {
public:
	static void InitChunks();
	// Procedurally generates chunk at a given positon
	static void GenerateChunk(int xPos, int yPos);

	// Gets a chunk from its position
	static Chunk* getChunk(int x, int y);
	// Gets a chunk from its world position
	static Chunk* getChunkWorld(float x, float y);
	// Sets a tile at given position. Finds the chunk automatically
	static void setTileAt(int x, int y, Tile tile);
	// Gets a tile at given position. Finds the chunk automatically
	static Tile* getTileAt(int x, int y);



	static std::unordered_map<int, std::unordered_map<int, Chunk>>* getChunks();
private:
	static std::unordered_map<int, std::unordered_map<int, Chunk>> chunks;
};