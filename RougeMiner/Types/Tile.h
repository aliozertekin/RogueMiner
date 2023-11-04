#pragma once
#include <SFML\Graphics.hpp>

class Chunk;

class Tile {
public:
	Tile();
	Tile(int type, int x, int y, Chunk* chunk);
	
	void Draw(sf::RenderWindow&);
private:
	int type;
	Chunk* chunk;
	int chunkX;
	int chunkY;
	sf::RectangleShape shape;
};