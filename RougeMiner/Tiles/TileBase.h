#pragma once
#include <SFML\Graphics.hpp>

class TileBase {
public:
	virtual void Draw(sf::RenderWindow&, sf::Sprite&);

	sf::IntRect textureRect;
	std::string textureID;
	std::string ID;
	std::string Name;
	std::string Description;
	int flags = 0;
	int hardness;

	static enum FLAGS {
		INVISIBLE = 1 << 0,
		NOCOLLISION = 1 << 1,
		UNBREAKABLE = 1 << 2
	};
};