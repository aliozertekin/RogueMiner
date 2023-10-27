#include "Game.h"

Player Game::player;
sf::Clock Game::DeltaClock;
sf::Time Game::deltaTime;

void Game::InitGame()
{
	TextureManager::LoadTextures();
	player.SetTexture(TextureManager::playerTexture);
}

void Game::Tick() {
	player.keyPressed(Game::deltaTime);

	deltaTime = DeltaClock.restart();
}

void Game::Draw(sf::RenderWindow& window) {
	
	player.playerAnimation(deltaTime);

	player.draw(window);
}

Player Game::GetPlayer()
{
	return player;
}
