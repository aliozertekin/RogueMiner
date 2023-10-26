#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

static class TextureManager {
public:
	static void LoadTextures();
	static sf::Texture playerTexture;
};