#pragma once
#include <vector>
#include "Tile.h"

class Chunk {
public:
	Chunk();
	Chunk(int x, int y);
	void Draw(sf::RenderWindow& window);
	void DebugDraw(sf::RenderWindow& window);
	static sf::Vector2i getChunkPos(Chunk*);
	sf::Vector2i getChunkPos();
	// Gets the tile at given position
	Tile* getTileAt(int x, int y);
	Tile* getTileAt(sf::Vector2i);
	// Sets the tile at given position
	void setTileAt(int x, int y, TileBase* tile);
	void setTileAt(int x, int y, Tile tile);
	// Returns the world coordinates of a tile
	sf::Vector2f tileToWorldCoordinates(int x, int y);
	sf::Vector2f tileToWorldCoordinates(sf::Vector2f);
	sf::Vector2f tileToWorldCoordinates(sf::Vector2i);
private:
	Tile tiles[16][16];
	int posX;
	int posY;
	sf::RectangleShape debugShape;
};
