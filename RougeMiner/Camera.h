#pragma once
#include <SFML\Graphics.hpp>
constexpr int WINDOW_WIDTH = 1920;
constexpr int WINDOW_HEIGHT = 1080;

class Camera {
public:
	static void setViews(sf::View* gameView, sf::View* hudView);
	static sf::Vector2f getGameViewMousePos();
	static void Tick();
	static void setZoomLevel();
	static void keyPressed(sf::Event event, sf::Time deltaTime);
	static void mapPixelToCoords(sf::RenderWindow& );
private:
	static float mouseRatio;
	static sf::Vector2f worldPos;
	static sf::Vector2f gameViewMousePos;
	static int wheelDelta;
	static float prevZoomLevel;
	static sf::View* gameView;
	static sf::View* hudView;
	static float zoomLevel;
	static float zoomTarget;
	static sf::Vector2f gameViewSize;
};