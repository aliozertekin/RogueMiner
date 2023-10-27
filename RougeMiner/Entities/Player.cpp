#include "Player.h"

Player::Player() {

	sf::Vector2f size = sf::Vector2f(SPRITE_WIDTH, SPRITE_HEIGHT);
	sf::Vector2f pos = sf::Vector2f(50, 50);

	playerSprite.setOrigin(16, 16);
	playerSprite.setPosition(pos.x - size.x / 2, pos.y - size.y / 2);
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
	}
	playerFrame++;
}

void Player::keyPressed() {
	//SETSCALE DÜZGÜN ÇALIÞMIYOR MUHTEMELEN TÝLEMAPTE BÝ PROBLEM VAR...

	//HALLETTÝM..
	if(xSpeed > 0 || ySpeed > 0){ playerState = 1; }
	else if (xSpeed == 0 && ySpeed == 0) { playerState = 0; }


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		xSpeed = -movementSpeed;
		playerSprite.setScale(-1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		ySpeed = movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		xSpeed = movementSpeed;
		playerSprite.setScale(1.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		ySpeed = -movementSpeed;
	}
}




