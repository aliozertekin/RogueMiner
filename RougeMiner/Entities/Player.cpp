#include "Player.h"

Player::Player() {
	playerSprite.setPosition(50, 50);
}

void Player::SetTexture(sf::Texture texture)
{
	playerSheet = texture;
	playerSprite.setTexture(playerSheet);

}


void Player::draw(sf::RenderWindow& window)
{
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

