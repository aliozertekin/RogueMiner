#include "Game.h"
#include <map>
#define DEBUG true

Player Game::player;
sf::Clock Game::DeltaClock;
sf::Time Game::deltaTime;
sf::View Game::gameView;

void Game::InitGame()
{
	TextureManager::LoadTextures();
	player.SetTexture(TextureManager::playerTexture);
	Camera::setViews(&gameView, Hud::getView());
	TileManager::RegisterTiles();
	ChunkManager::setTileSheet(TextureManager::tileTexture);
	ChunkManager::InitChunks();
	gameView.setSize(static_cast<float>(WINDOW_WIDTH / 2), static_cast<float>(WINDOW_HEIGHT / 2));
	Hud::Init(gameView.getSize().x, gameView.getSize().y);
}

void Game::EventHandler(sf::Event& event) {
	Camera::keyPressed(event, Game::deltaTime);
}

void Game::Tick() {
	player.keyPressed(Game::deltaTime);
	Camera::Tick();
}

void Game::Draw(sf::RenderWindow& window) {
	DrawView(window);
	player.playerAnimation();
	player.draw(window);
	player.tileLookedAt(window);
	std::unordered_map<int, std::unordered_map<int, Chunk>>* chunks = ChunkManager::getChunks();

	/*for (auto& xPair : *chunks) {
		int xPos = xPair.first; // X coordinate

		auto& yMap = xPair.second;
		for (auto& yPair : yMap) {
			int yPos = yPair.first; // Y coordinate
			Chunk& chunk = yPair.second; // Chunk
			chunk.Draw(window);
			
			#ifdef DEBUG 
			chunk.DebugDraw(window);
			#endif
		}
	}*/

	Hud::Draw(window, player.getPos());
	deltaTime = DeltaClock.restart();
}

void Game::DrawView(sf::RenderWindow& window)
{
	gameView.setCenter(player.getPos());
	window.setView(gameView);
}

Player Game::GetPlayer()
{
	return player;
}
