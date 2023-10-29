#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "TextureManager.h"
#include "GUI/Hud.h"
#include "ChunkManager.h"
#include "Camera.h"

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;

class Game {
public:
	static void InitGame();
	static void Tick();
	static void Draw(sf::RenderWindow&);
	static void EventHandler(sf::Event&);

	static Player GetPlayer();
	static sf::Time deltaTime;
private:
	static void DrawView(sf::RenderWindow& window);
	static sf::View gameView;
	static Player player;
	static sf::Clock DeltaClock;
};