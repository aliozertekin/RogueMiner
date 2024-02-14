#include "AnimationManager.h"


sf::Sprite AnimationManager::selectorSprite;
int AnimationManager::selectorFrame;

void AnimationManager::Animate()
{
	playerAnimation();
	selectorAnimation();
	
}

void AnimationManager::Initialize()
{
	selectorSprite.setTexture(TextureManager::selectorTexture);


	Player::playerFrame = 0;
	Player::playerDirection = 0;
	selectorFrame = 0;
	Player::shownFPS = 8;
}

sf::Sprite AnimationManager::getSelectorSprite()
{
	return selectorSprite;
}

void AnimationManager::setSelectorSprite(sf::Sprite selector) 
{
	selectorSprite = selector;
}

void AnimationManager::playerAnimation()
{
	switch (Player::playerState) {
		case Player::playerStates::Idle:
		{

			Player::playerFrame = 0;
			Player::playerSprite.setTextureRect(sf::IntRect(Player::playerFrame * SPRITE_WIDTH, Player::playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
			break;
		}
		case Player::playerStates::Running: {
			
			Player::playerSprite.setTextureRect(sf::IntRect(Player::playerFrame * SPRITE_WIDTH, Player::playerDirection * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
			break;

		}
	}
	Player::spriteTime = Player::spriteClock.getElapsedTime();
	Player::playerFrame = (int) floor(Player::spriteTime.asSeconds() * Player::shownFPS) % 4;
}

void AnimationManager::selectorAnimation()
{
	selectorSprite.setTextureRect(sf::IntRect(selectorFrame * 32, 0, 32, 32));

	Player::spriteTime = Player::spriteClock.getElapsedTime();
	selectorFrame = (int) floor(Player::spriteTime.asSeconds() * Player::shownFPS/4) % 3;
}