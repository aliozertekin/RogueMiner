#include "TextureManager.h"

sf::Texture TextureManager::playerTexture;

void TextureManager::LoadTextures()
{
	if (!playerTexture.loadFromFile("Assets/Player.png")) {
		std::cout << "Couldn't load file..";
	}

}
