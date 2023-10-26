#include "Game.h"

Player Game::player;

void Game::InitGame()
{
	TextureManager::LoadTextures();
	player.SetTexture(TextureManager::playerTexture);
}

Player Game::GetPlayer()
{
	return player;
}
