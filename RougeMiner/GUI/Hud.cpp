#include "Hud.h"
#include <iostream>
Hud::Hud()
{

	//HUD TEST

	if (!font.loadFromFile("Assets/Poppins-Regular.ttf")) { std::cout << "Font not selected!"; }
	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("Hello world");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Red);

}

void Hud::drawHud(sf::RenderWindow& window, sf::Vector2f playerpos)
{
	Hud hud;


	hud.text.setPosition(hud.hudCenter.x - hud.hudSize.x / 2, hud.hudCenter.y - hud.hudSize.y / 2);
	hudView.setCenter(playerpos);
	window.setView(hudView);
	window.draw(hud.text);
	
}

void Hud::InitHudView(float gamewindow_W, float gamewindow_H)
{
	
	hudView.setSize(gamewindow_W, gamewindow_H);
}