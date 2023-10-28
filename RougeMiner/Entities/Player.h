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

	void keyPressed(sf::Time deltaTime);

	enum playerStates {
		Idle,
		Running,
		Mining
	};
	sf::Vector2f getPlayerPos();
private:
	int playerFrame = 0;
	sf::Texture playerSheet;
	sf::Sprite playerSprite;
	int playerState = 0;
	bool checkIdle = true;
<<<<<<< Updated upstream

=======
	sf::Clock spriteClock;
	sf::Time spriteTime;
	sf::Vector2f playerSpeed = sf::Vector2f(xSpeed,ySpeed);
>>>>>>> Stashed changes
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	float movementSpeed =80.0f;
	float friction = 0.96f;
};