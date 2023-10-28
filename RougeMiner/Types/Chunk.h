#pragma once
#include <vector>
#include "Tile.h"

class Chunk {
public:
	Chunk();
	Chunk(int x, int y);
	void DebugDraw(sf::RenderWindow& window);

	Tile getTileAt(int x, int y);
	void setTileAt(int x, int y, Tile tile);
private:
	Tile tiles[16][16];
	int posX;
	int posY;
	sf::RectangleShape debugShape;
};
