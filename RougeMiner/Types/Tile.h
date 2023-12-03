#pragma once
#include <SFML\Graphics.hpp>
#include "../Tiles/TileBase.h"

class Chunk;

class Tile {
public:
	Tile();
	Tile(TileBase* type, int x, int y, Chunk* chunk, sf::Texture* texture);
	Tile(TileBase* type, sf::Texture* texture);
	
	void Draw(sf::RenderWindow&);
	sf::Vector2i GetPos();
	void SetType(TileBase* type);
	TileBase* GetType();
	sf::Sprite getSprite();
	void setSprite();
private:
	TileBase* type;
	Chunk* chunk;
	int tileX;
	int tileY;
	sf::Sprite sprite;
};