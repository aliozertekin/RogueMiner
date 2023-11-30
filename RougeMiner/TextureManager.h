#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class TextureManager {
public:
	static void LoadTextures();

	static sf::Texture playerTexture;
	static sf::Texture tileTexture;
};