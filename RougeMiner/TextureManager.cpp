#include "TextureManager.h"

sf::Texture TextureManager::playerTexture;

void TextureManager::LoadTextures()
{
<<<<<<< Updated upstream
	if (!playerTexture.loadFromFile("Assets/Player.png")) {
		std::cout << "Couldn't load file..";
=======
	if (!playerTexture.loadFromFile("Assets/Player1.png")) {
		std::cout << "Couldn't load file 'Player1.png'..";
>>>>>>> Stashed changes
	}

}
