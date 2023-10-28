#pragma once
#include <SFML\Graphics.hpp>

class Chunk;

class Tile {
public:
	Tile();
	Tile(int type, int x, int y, Chunk* chunk);
private:
	int type;
	Chunk* chunk;
	int posX;
	int posY;
};