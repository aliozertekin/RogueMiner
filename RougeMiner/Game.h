#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "TextureManager.h"

class Game {
public:
	static void InitGame();

	static Player GetPlayer();

	static sf::Clock DeltaTime;
private:
	static Player player;
};