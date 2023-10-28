#include "Game.h"

Player Game::player;
sf::Clock Game::DeltaClock;
sf::Time Game::deltaTime;

void Game::InitGame()
{
	TextureManager::LoadTextures();
	player.SetTexture(TextureManager::playerTexture);
	gameView.setSize(static_cast<float>(WINDOW_WIDTH / 2), static_cast<float>(WINDOW_HEIGHT / 2));
	Hud::InitHudView(gameView.getSize().x, gameView.getSize().y);
}

void Game::Tick() {
	player.keyPressed(Game::deltaTime);

	deltaTime = DeltaClock.restart();
}

void Game::Draw(sf::RenderWindow& window) {
<<<<<<< Updated upstream
	player.playerAnimation();
=======
	player.playerAnimation(deltaTime);


	
>>>>>>> Stashed changes
	player.draw(window);
	
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
