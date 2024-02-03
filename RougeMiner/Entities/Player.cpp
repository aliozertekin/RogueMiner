#include "Player.h"

#include <math.h>
#include <iostream>

int Player::playerState;
sf::Texture Player::playerSheet;
sf::Sprite Player::playerSprite;
int Player::playerFrame;
int Player::playerDirection;
int Player::shownFPS;
sf::Clock Player::spriteClock;
sf::Time Player::spriteTime;
Tile* Player::targetTile;
Chunk* Player::targetChunk;


Player::Player() {
	

	playerSprite.setOrigin(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2);
	playerSprite.setPosition(0, 0);
}

void Player::TileLook()
{
	sf::Vector2f playerPos = playerSprite.getPosition();
	Chunk* chunk = ChunkManager::getChunkWorld(playerPos);
	sf::Vector2i chunkPos = chunk->getChunkPos();
	
	
	sf::Vector2i tilePos = sf::Vector2i( floor(playerPos.x / 32.0f) , floor(playerPos.y / 32.0f));
	tilePos = sf::Vector2i(tilePos.x % 16, tilePos.y % 16);
	if (tilePos.x < 0) tilePos.x += 16;
	if (tilePos.y < 0) tilePos.y += 16;

	switch (playerDirection){
		case playerDirections::Down:{
			if (tilePos.y == 15){
				targetChunk = ChunkManager::getChunk(chunkPos.x, chunkPos.y + 1);
				targetTile = targetChunk->getTileAt(tilePos.x, 0);
				
			}
			else 
			{
				targetChunk = chunk;
				targetTile = ChunkManager::getTileAt(tilePos.x, tilePos.y + 1);
			}
			break;
		}
		case playerDirections::Left:{
			if (tilePos.x == 0) {
				targetChunk = ChunkManager::getChunk(chunkPos.x - 1, chunkPos.y);
				targetTile = targetChunk->getTileAt(15, tilePos.y);
			}
			else 
			{
				targetChunk = chunk;
				targetTile = ChunkManager::getTileAt(tilePos.x - 1, tilePos.y);
			}
			break;
		}
		case playerDirections::Right:{
			if (tilePos.x == 15) {
				targetChunk = ChunkManager::getChunk(chunkPos.x + 1, chunkPos.y);
				targetTile = targetChunk->getTileAt(0, tilePos.y);
			}
			else 
			{
				targetChunk = chunk;
				targetTile = ChunkManager::getTileAt(tilePos.x + 1, tilePos.y);
			}
			break;
		}
		case playerDirections::Up:{
			if (tilePos.y == 0) {
				targetChunk = ChunkManager::getChunk(chunkPos.x, chunkPos.y - 1);
				targetTile = targetChunk->getTileAt(tilePos.x, 15);
			}
			else 
			{
				targetChunk = chunk;
				targetTile = ChunkManager::getTileAt(tilePos.x, tilePos.y - 1);
			}
			break;
		}
	}
}

void Player::SetTexture(sf::Texture texture)
{
	playerSheet = texture;
	playerSprite.setTexture(playerSheet);
}

void Player::draw(sf::RenderWindow& window)
{
	playerSpeed.x *= friction;
	playerSpeed.y *= friction;
	
	
	playerSprite.move(playerSpeed.x, playerSpeed.y);
	
	window.draw(playerSprite);
}



std::unique_ptr<Player> Player::createPlayer(ClassBase base)
{
	std::unique_ptr<Player> p(new Player);
	p->health = base.Health;
	p->stamina = base.Stamina;
	return p;
}

Chunk* Player::getChunkLookedAt()
{
	return targetChunk;
}

Tile* Player::getTileLookedAt()
{
	return targetTile;
}

void Player::keyPressed(sf::Time deltaTime) {

	if (playerSpeed.x + playerSpeed.y > 0.9f) { playerSpeed.x * 0.7f; playerSpeed.y * 0.7f; }
	
	if (abs(playerSpeed.x) > 0 || abs(playerSpeed.y) > 0 ) { playerState = 1; }
	if (abs(playerSpeed.x) < 0.2f && abs(playerSpeed.y) < 0.2f) { playerState = 0; }

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerSpeed.y = movementSpeed * deltaTime.asSeconds();
		playerDirection = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		playerSpeed.x = -movementSpeed * deltaTime.asSeconds();
		playerDirection = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		playerSpeed.x = movementSpeed * deltaTime.asSeconds();
		playerDirection = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		playerSpeed.y = -movementSpeed * deltaTime.asSeconds();
		playerDirection = 3;
	}
}

sf::Vector2f Player::getPos()
{
	return playerSprite.getPosition();
}


