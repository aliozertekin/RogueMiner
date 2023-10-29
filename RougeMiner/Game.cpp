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
	gameView.setCenter(player.getPlayerPos());
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
	InitView(window);
}

void Game::Zoom(sf::Event& event)
{
	int zoomConstant = 8;
	int zoomSpeed = event.mouseWheel.delta * zoomConstant;
	//FIX THIS
	if (event.type == sf::Event::MouseWheelMoved)
	{
		std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
		if (gameView.getSize().x < WINDOW_WIDTH - zoomConstant && gameView.getSize().y < WINDOW_HEIGHT - zoomConstant)
		{
			gameView.setSize(gameView.getSize().x + zoomSpeed, gameView.getSize().y + zoomSpeed);
			std::cout << "gameview size: " << gameView.getSize().x << std::endl;
		}


		
		Hud::InitHudView(gameView.getSize().x, gameView.getSize().y);
	}
}

void Game::eventCalls(sf::Event& event)
{
	Zoom(event);
}

void Game::InitView(sf::RenderWindow& window)
{	
	window.setView(gameView);
}

Player Game::GetPlayer()
{
	return player;
}
