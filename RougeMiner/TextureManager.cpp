#include "TextureManager.h"

sf::Texture TextureManager::playerTexture;

void TextureManager::LoadTextures()
{
	if (!playerTexture.loadFromFile("Assets/Player1.png")) {
		std::cout << "Couldn't load file 'Player1.png'..";
	}

}
