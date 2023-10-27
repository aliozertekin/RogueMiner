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

void Player::playerAnimation()
{
	
	switch (playerState) {
		case playerStates::Idle: {
			if (playerFrame > 1) { playerFrame = 0; }
			playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
			
			break;
		}
		case playerStates::Running: {
			if (playerFrame > 7) { playerFrame = 0; }
			playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 3 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
			
			break;
		}
		case playerStates::Mining: {
			if (playerFrame > 7) { playerFrame = 0; }
			playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 8 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));

			break;
		}
	}
	playerFrame++;
}

void Player::keyPressed(sf::Time deltaTime) {

	//TO-DO BETTER ANIMATION SYSTEM...
	
	if (abs(xSpeed) > 0 || abs(ySpeed) > 0 ) { playerState = 1; }
	if (abs(xSpeed) < 0.15f && abs(ySpeed) < 0.15f) { playerState = 0; }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		xSpeed = -movementSpeed * deltaTime.asSeconds();
		playerSprite.setScale(-1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		ySpeed = movementSpeed * deltaTime.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		xSpeed = movementSpeed * deltaTime.asSeconds();
		playerSprite.setScale(1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		ySpeed = -movementSpeed * deltaTime.asSeconds();
	}
}