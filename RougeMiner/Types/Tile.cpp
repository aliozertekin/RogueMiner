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
	this->type->Draw(window, this->sprite);
}

sf::Vector2i Tile::GetPos()
{
	if (this == nullptr)
		return sf::Vector2i(0, 0);
	return sf::Vector2i(tileX, tileY);
}

void Tile::SetType(TileBase* tile)
{
	this->type = tile;
	sprite.setTextureRect(type->textureRect);
}

TileBase* Tile::GetType()
{
	if (this == nullptr)
		return TileManager::GetTile("NULL");
	return type;
}

sf::Vector2f Tile::tileToWorld()
{
	return sf::Vector2f(this->chunk->getChunkPos().x * 512 + this->tileX * 32, this->chunk->getChunkPos().y * 512 + this->tileY * 32);
}



