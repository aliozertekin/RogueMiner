#include "Tile.h"
#include "Chunk.h"

Tile::Tile()
{
}

Tile::Tile(int type, int x, int y, Chunk* chunk)
{
	this->chunk = chunk;
	this->chunkX = x;
	this->chunkY = y;
	this->type = type;

	sf::Vector2f worldPos = chunk->tileToWorldCoordinates(x, y);
	shape.setPosition(worldPos);
	shape.setSize(sf::Vector2f(32.0, 32.0));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(2.0);
	shape.setOutlineColor(sf::Color::Green);
}

void Tile::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
