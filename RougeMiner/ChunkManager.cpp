#include "ChunkManager.h"
#include "TileManager.h"

std::unordered_map<int, std::unordered_map<int, Chunk>> ChunkManager::chunks;
sf::Texture ChunkManager::tileSheet;


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
	// Precache
	TileBase* stone = TileManager::GetTile("RM_STONE");

	auto chunk = std::make_shared<Chunk>(xPos, yPos);
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {

			int rand = Utils::GetRandomRangeSeed(0, 99);

			if (rand < 90) {
				chunk->setTileAt(x, y, *std::make_shared<Tile>(stone, x, y, chunk.get(), &tileSheet));
			}
			else {
				chunk->setTileAt(x, y, *std::make_shared<Tile>(TileManager::GetRandomOre(), x, y, chunk.get(), &tileSheet));
			}
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

Chunk* ChunkManager::getChunkWorld(sf::Vector2f pos)
{
	int chunkX = static_cast<int>(floor(pos.x / 512.0f));
	int chunkY = static_cast<int>(floor(pos.y / 512.0f));
	return getChunk(chunkX, chunkY);
}

Chunk* ChunkManager::getChunkWorld(float x, float y)
{
	int chunkX = static_cast<int>(floor(x / 512.0f));
	int chunkY = static_cast<int>(floor(y / 512.0f));
	return getChunk(chunkX, chunkY);
}

void ChunkManager::setTileAt(int x, int y, TileBase* tile)
{
	int chunkX = static_cast<int>(floor(static_cast<float>(x) / 16.0f));
	int chunkY = static_cast<int>(floor(static_cast<float>(y) / 16.0f));
	Chunk* chunk = getChunk(chunkX, chunkY);
	chunk->setTileAt(x % 16, y % 16, tile);
}

Tile* ChunkManager::getTileAt(int x, int y)
{
	int chunkX = static_cast<int>(floor(static_cast<float>(x) / 16.0f));
	int chunkY = static_cast<int>(floor(static_cast<float>(y) / 16.0f));
	Chunk* chunk = getChunk(chunkX, chunkY);
	return chunk->getTileAt( x % 16, y % 16);
}

void ChunkManager::setTileSheet(sf::Texture texture)
{
	tileSheet = texture;
}

Tile* ChunkManager::worldToTileCoordinates(sf::Vector2f world)
{
	return getChunkWorld(world)->getTileAt(((int)world.x%512)/32, ((int)world.y % 512) / 32);


	
	
		
}

std::unordered_map<int, std::unordered_map<int, Chunk>>* ChunkManager::getChunks()
{
	return &chunks;
}



