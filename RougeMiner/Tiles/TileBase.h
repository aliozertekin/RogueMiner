#pragma once
#include <SFML\Graphics.hpp>

class TileBase {
public:
	virtual void Draw(sf::RenderWindow&, sf::Sprite&);

	sf::IntRect textureRect;
	std::string ID;
	std::string Name;
	std::string Description;
	int flags;
	int hardness;

	static enum FLAGS {
		INVISIBLE = 1 << 0,
		NOCOLLISION = 1 << 1,
		UNBREAKABLE = 1 << 2
	};
};