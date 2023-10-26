#pragma once
#include <SFML/Graphics.hpp>

constexpr auto SPRITE_WIDTH = 32;
constexpr auto SPRITE_HEIGHT = 32;

class Player {

public:
	Player();

	void SetTexture(sf::Texture texture);
	void draw(sf::RenderWindow&);
	void playerAnimation();

	enum playerStates {
		Idle,
		Running
	};
private:
	int playerFrame = 0;
	sf::Texture playerSheet;
	sf::Sprite playerSprite;
	int playerState = 1;
};