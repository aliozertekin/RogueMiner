#include "Tile.h"
#include "Chunk.h"

Tile::Tile()
{
}

Tile::Tile(TileBase* type, int x, int y, Chunk* chunk, sf::Texture* texture)
{
	this->chunk = chunk;
	this->tileX = x;
	this->tileY = y;
	this->type = type;

	sf::Vector2f worldPos = chunk->tileToWorldCoordinates(x, y);
	sprite.setPosition(worldPos);
	sprite.setTexture(*texture);
	sprite.setTextureRect(type->textureRect);
}

void Tile::Draw(sf::RenderWindow& window)
{
	//window.draw(sprite);
	type->Draw(window, sprite);
}

sf::Vector2i Tile::GetPos()
{
	return sf::Vector2i(tileX, tileY);
}

void Tile::SetType(TileBase* tile)
{
	type = tile;
}

TileBase* Tile::GetType()
{
	return type;
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}
