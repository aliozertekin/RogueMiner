#pragma once
#include <vector>
#include "Tile.h"

class Chunk {
public:
	Chunk();
	Chunk(int x, int y);
	void Draw(sf::RenderWindow& window);
	void DebugDraw(sf::RenderWindow& window);

	// Gets the tile at given position
	Tile* getTileAt(int x, int y);
	// Sets the tile at given position
	void setTileAt(int x, int y, Tile tile);
	// Returns the world coordinates of a tile
	sf::Vector2f tileToWorldCoordinates(int x, int y);
private:
	Tile tiles[16][16];
	int posX;
	int posY;
	sf::RectangleShape debugShape;
};
