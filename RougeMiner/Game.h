#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "TextureManager.h"
#include "GUI/Hud.h"
#include "ChunkManager.h"

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;
static sf::View gameView;


class Game {
public:
	static void InitGame();
	static void Tick();
	static void Draw(sf::RenderWindow&);
	static Player GetPlayer();
	static sf::Time deltaTime;
private:
	static void InitView(sf::RenderWindow& window);
	static Player player;
	static sf::Clock DeltaClock;
};