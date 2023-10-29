#pragma once
#include <SFML\Graphics.hpp>

class Camera {
public:
	static void setViews(sf::View* gameView, sf::View* hudView);

	static void Tick();
	static void setZoomLevel(float zoom);
	static void keyPressed(sf::Event event, sf::Time deltaTime);
private:
	static sf::View* gameView;
	static sf::View* hudView;
	static float zoomLevel;
	static float zoomTarget;
};