#include "Hud.h"

Hud::Hud()
{
}

void Hud::drawHud(sf::RenderWindow& window, sf::Vector2f playerpos)
{
	hudView.setCenter(playerpos);
	window.setView(hudView);
	
}

void Hud::InitHudView(float gamewindow_W, float gamewindow_H)
{
	hudView.setSize(gamewindow_W, gamewindow_H);
}