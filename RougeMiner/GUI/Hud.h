#pragma once
#include <SFML/Graphics.hpp>


class Hud {
public:
	static void Init(float windowW, float windowH);
	static void Draw(sf::RenderWindow&, sf::Vector2f playerpos);

	static sf::View* getView();
private:
	static sf::View hudView;
};