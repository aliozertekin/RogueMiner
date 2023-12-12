#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <map>

class TextureManager {
public:
	static void LoadTextures();
	static sf::IntRect GetTextureRect(std::string name);

	static sf::Texture playerTexture;
	static sf::Texture tileTexture;
private:
	static sf::Texture StitchTextures(const std::string& folderPath);
	static std::map<std::string, sf::IntRect> textureRegistry;
};