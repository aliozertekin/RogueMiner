#include "Game.h"
#include <map>
#define DEBUG true

Player Game::player;
sf::Clock Game::DeltaClock;
sf::Time Game::deltaTime;

void Game::InitGame()
{
	TextureManager::LoadTextures();
	player.SetTexture(TextureManager::playerTexture);
	ChunkManager::InitChunks();
	gameView.setSize(static_cast<float>(WINDOW_WIDTH / 2), static_cast<float>(WINDOW_HEIGHT / 2));
	Hud::InitHudView(gameView.getSize().x, gameView.getSize().y);
}

void Game::Tick() {
	player.keyPressed(Game::deltaTime);

	deltaTime = DeltaClock.restart();
}

void Game::Draw(sf::RenderWindow& window) {

	player.playerAnimation();
	player.draw(window);
	
	#if DEBUG
		std::unordered_map<int, std::unordered_map<int, Chunk>>* chunks = ChunkManager::getChunks();

		for (auto& xPair : *chunks) {
			int xPos = xPair.first; // X coordinate

			auto& yMap = xPair.second;
			for (auto& yPair : yMap) {
				int yPos = yPair.first; // Y coordinate
				Chunk& chunk = yPair.second; // Chunk
				chunk.DebugDraw(window);
			}
		}
	#endif

	Hud::drawHud(window , player.getPlayerPos());
}

void Game::InitView(sf::RenderWindow& window)
{
	gameView.setCenter(player.getPlayerPos());
	window.setView(gameView);
}

Player Game::GetPlayer()
{
	return player;
}
