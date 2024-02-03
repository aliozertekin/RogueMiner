#pragma once
#include "AnimationManager.h"
#include "Camera.h"
#include "ChunkManager.h"
#include "Entities/Player.h"
#include "GUI/Hud.h"
#include "TextureManager.h"
#include "TileManager.h"
#include <SFML/Graphics.hpp>


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