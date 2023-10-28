#pragma once
#include <SFML/Graphics.hpp>


static sf::View hudView;
class Hud {
public:
	Hud();
	static void drawHud(sf::RenderWindow&, sf::Vector2f playerpos);
	static void InitHudView(float gamewindow_W, float gamewindow_H);
private:
	
	


	

};