#include "TextureManager.h"

sf::Texture TextureManager::playerTexture;
sf::Texture TextureManager::tileTexture;

void TextureManager::LoadTextures()
{
	if (!playerTexture.loadFromFile("Assets/Player.png")) {
		std::cout << "Couldn't load file 'Player.png'!";
	}
	if (!tileTexture.loadFromFile("Assets/tilesheet.png")) {
		std::cout << "Couldn't load file 'tilesheet.png'!";
	}
}
