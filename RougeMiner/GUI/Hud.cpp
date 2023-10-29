#include "Hud.h"

sf::View Hud::hudView;

void Hud::Draw(sf::RenderWindow& window, sf::Vector2f playerpos)
{
	
}

sf::View* Hud::getView()
{
	return &hudView;
}

void Hud::Init(float windowW, float windowH)
{
	hudView.setSize(windowW, windowH);
}