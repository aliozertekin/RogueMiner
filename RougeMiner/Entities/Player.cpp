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
	playerSpeed.x *= friction;
	playerSpeed.y *= friction;
	
	
	playerSprite.move(playerSpeed.x, playerSpeed.y);

	window.draw(playerSprite);
}

void Player::playerAnimation()
{
	
	switch (playerState) {
		case playerStates::Idle: {
<<<<<<< Updated upstream
			if (playerFrame > 1) { playerFrame = 0; }
			playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
			
=======
			switch (playerDirection)
			{
				case playerDirections::Down:{
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
>>>>>>> Stashed changes
			break;
		}
		case playerStates::Running: {
			if (playerFrame > 7) { playerFrame = 0; }
			playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 3 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
			
<<<<<<< Updated upstream
			break;
		}
		case playerStates::Mining: {
			if (playerFrame > 7) { playerFrame = 0; }
			playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, 8 * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));

=======
			switch (playerDirection)
			{
			
				case playerDirections::Down: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart(); }
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Left: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart();}
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Right: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart();}
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
				case playerDirections::Up: {
					if (playerFrame > 3) { playerFrame = 0; spriteClock.restart();}
					playerSprite.setTextureRect(sf::IntRect(playerFrame * SPRITE_WIDTH, playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
					break;
				}
			}
>>>>>>> Stashed changes
			break;
		}
	}
	playerFrame++;
}

void Player::keyPressed(sf::Time deltaTime) {

	//TO-DO BETTER ANIMATION SYSTEM...
	if (playerSpeed.x + playerSpeed.y > 0.9f) { playerSpeed.x * 0.7f; playerSpeed.y * 0.7f; }
	
	if (abs(playerSpeed.x) > 0 || abs(playerSpeed.y) > 0 ) { playerState = 1; }
	if (abs(playerSpeed.x) < 0.15f && abs(playerSpeed.y) < 0.15f) { playerState = 0; }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
<<<<<<< Updated upstream
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
=======
		playerSpeed.x = -movementSpeed * deltaTime.asSeconds();
		playerDirection = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerSpeed.y = movementSpeed * deltaTime.asSeconds();
		playerDirection = 0;
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

sf::Vector2f Player::getPlayerPos()
{
	return playerSprite.getPosition();
}

>>>>>>> Stashed changes
