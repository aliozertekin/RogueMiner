#pragma once
#include <SFML/Graphics.hpp>

constexpr auto SPRITE_WIDTH = 48;
constexpr auto SPRITE_HEIGHT = 48;

class Player {

public:
	Player();

	void SetTexture(sf::Texture texture);
	void draw(sf::RenderWindow&);
	void playerAnimation();

	void keyPressed(sf::Time deltaTime);

	enum playerStates {
		Idle,
		Running
	};
	enum playerDirections {
		Down,
		Left,
		Right,
		Up
	};
	sf::Vector2f getPlayerPos();
private:
	int playerFrame = 0;
	sf::Texture playerSheet;
	sf::Sprite playerSprite;
	int playerState = 0;
	int playerDirection = 0;
	int shownFPS = 8;
	sf::Clock spriteClock;
	sf::Time spriteTime;
	sf::Vector2f playerSpeed = sf::Vector2f(xSpeed,ySpeed);

	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	float movementSpeed =80.0f;
	float friction = 0.90f;
};