#include "Tile.h"
#include "Chunk.h"

Tile::Tile()
{
}

Tile::Tile(int type, int x, int y, Chunk* chunk)
{
	this->chunk = chunk;
	this->posX = x;
	this->posY = y;
	this->type = type;
}
