#include "Player.h"
#include <math.h>
#include <iostream>

Player::Player() {
	playerSprite.setOrigin(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2);
	playerSprite.setPosition(0,0);
}

Tile* Player::tileLookedAt(sf::RenderWindow& window)
{
	sf::Vector2f playerPos = playerSprite.getPosition();
	Chunk* chunk = ChunkManager::getChunkWorld(floor(playerPos.x),floor(playerPos.y));
	if (chunk != nullptr)
		chunk->DebugDraw(window);
	sf::Vector2f tilePos = sf::Vector2f(floor(playerPos.x / 32.0f), floor(playerPos.y / 32.0f));
	
	switch (playerDirection){
		case playerDirections::Down:{
			Tile* playertile = ChunkManager::getTileAt(tilePos.x, tilePos.y + 1);
			playertile->Draw(window);
			break;
		}
		case playerDirections::Left:{
			Tile* playertile = ChunkManager::getTileAt(tilePos.x - 1, tilePos.y);
			playertile->Draw(window);
			break;
		}
		case playerDirections::Right:{
			Tile* playertile = ChunkManager::getTileAt(tilePos.x + 1, tilePos.y);
			playertile->Draw(window);
			break;
		}
		case playerDirections::Up:{
			Tile* playertile = ChunkManager::getTileAt(tilePos.x, tilePos.y - 1);
			playertile->Draw(window);
			break;
		}
		default:{
			Tile* playertile = ChunkManager::getTileAt(tilePos.x, tilePos.y);
			playertile->Draw(window);
			break; 
		}
	}
	
	return NULL;
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

void Player::playerAnimation()
{
	switch (playerState) {
		case playerStates::Idle: {
			switch (playerDirection)
			{
				case playerDirections::Down: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Left: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Right: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Up: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
			}
			break;
		}
		case playerStates::Running: {
			switch (playerDirection)
			{
				case playerDirections::Down: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart(); }
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Left: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart(); }
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Right: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart(); }
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Up: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart(); }
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
			}
			break;
		}
	}
	spriteTime = spriteClock.getElapsedTime();
	playerFrame = floor(spriteTime.asSeconds() * shownFPS);
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


