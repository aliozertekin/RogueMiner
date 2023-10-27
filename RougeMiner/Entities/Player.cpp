#include "Player.h"
#include <math.h>

Player::Player() {
	sf::Vector2f pos = sf::Vector2f(0, 0);

	playerSprite.setOrigin(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2);
	playerSprite.setPosition(pos.x, pos.y);
}

void Player::SetTexture(sf::Texture texture)
{
	playerSheet = texture;
	playerSprite.setTexture(playerSheet);
}

void Player::draw(sf::RenderWindow& window)
{
	xSpeed *= friction;
	ySpeed *= friction;
	
	
	playerSprite.move(xSpeed,ySpeed);

	window.draw(playerSprite);
}

void Player::playerAnimation(sf::Time deltaTime)
{
	
	switch (playerState) {
		case playerStates::Idle: {
			switch (playerDirection)
			{
				case playerDirections::Down:{
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 0 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Left: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 1 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Right: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 2 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Up: {
					playerFrame = 0;
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 3 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
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
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 0 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Left: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart();}
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 1 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Right: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart();}
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 2 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Up: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart();}
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 3 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
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

	//TO-DO BETTER ANIMATION SYSTEM...
	
	if (abs(xSpeed) > 0 || abs(ySpeed) > 0 ) { playerState = 1; }
	if (abs(xSpeed) < 0.15f && abs(ySpeed) < 0.15f) { playerState = 0; }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		xSpeed = -movementSpeed * deltaTime.asSeconds();
		playerDirection = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		ySpeed = movementSpeed * deltaTime.asSeconds();
		playerDirection = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		xSpeed = movementSpeed * deltaTime.asSeconds();
		playerDirection = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		ySpeed = -movementSpeed * deltaTime.asSeconds();
		playerDirection = 3;
	}
}

