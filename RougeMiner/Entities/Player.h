#pragma once
#include <SFML/Graphics.hpp>

constexpr auto SPRITE_WIDTH = 48;
constexpr auto SPRITE_HEIGHT = 48;

class Player {

public:
	Player();

	void SetTexture(sf::Texture texture);
	void draw(sf::RenderWindow&);
	void playerAnimation(sf::Time deltaTime);

	void keyPressed(sf::Time deltaTime);

	enum playerStates {
		Idle,
		Running
	};
	enum playerDirections {
		Down,Left,Right,Up
	};
private:
	int playerFrame = 0;
	sf::Texture playerSheet;
	sf::Sprite playerSprite;
	int playerState = 0;
	int playerDirection = 0;
	int shownFPS = 8;
	bool checkIdle = true;
	sf::Clock spriteClock;
	sf::Time spriteTime;
	
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	float movementSpeed = 50.0f;
	float friction = 0.96f;
};