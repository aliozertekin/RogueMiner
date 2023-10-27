#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "TextureManager.h"

class Game {
public:
	static void InitGame();
	static void Tick();
	static void Draw(sf::RenderWindow&);

	static Player GetPlayer();

	static sf::Time deltaTime;
private:
	static Player player;
	static sf::Clock DeltaClock;
};