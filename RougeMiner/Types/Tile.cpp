#include "Tile.h"
#include "Chunk.h"
#include "..//AnimationManager.h"

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
	type->Draw(window, sprite);
}

sf::Vector2i Tile::GetPos()
{
	if (this == nullptr)
		return sf::Vector2i(0, 0);
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

void Tile::setSprite(sf::Sprite sp)
{
	sprite = sp;
}

