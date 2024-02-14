#include "Camera.h"
#include <iostream>
#include "Utils.h"


sf::View* Camera::gameView;
sf::View* Camera::hudView;
float Camera::zoomLevel;
float Camera::zoomTarget; 
float Camera::prevZoomLevel;
float Camera::mouseRatio;
sf::Vector2f Camera::gameViewSize;
int Camera::wheelDelta;
sf::Vector2f Camera::gameViewMousePos;
sf::Vector2f Camera::worldPos;
sf::Vector2f aspectRatio(static_cast<float>(WINDOW_WIDTH) / static_cast<float>(WINDOW_HEIGHT), 1);

void Camera::setViews(sf::View* gameView, sf::View* hudView)
{
	Camera::gameView = gameView;
	Camera::hudView = hudView;
	zoomLevel = 0.0;
	zoomTarget = 0.0;
}

sf::Vector2f Camera::getGameViewMousePos()
{
	return worldPos;
}

void Camera::Tick()
{
	gameViewSize = *&gameView->getSize();
	prevZoomLevel = zoomLevel;
	zoomLevel = Utils::lerp(zoomLevel, zoomTarget, 0.1f);
	Camera::setZoomLevel();
}
	
void Camera::setZoomLevel()
{
	//std::cout << gameViewSize.x << "\n" << gameViewSize.y << "\n";
	if (gameView == nullptr) return;

	gameView->setSize(gameViewSize.x + aspectRatio.x * 100 * (zoomLevel - prevZoomLevel), gameViewSize.y + aspectRatio.y * 100 * (zoomLevel - prevZoomLevel));
	if (gameViewSize.x >= WINDOW_WIDTH || gameViewSize.y >= WINDOW_HEIGHT)
		gameView->setSize(WINDOW_WIDTH - aspectRatio.x, WINDOW_HEIGHT - aspectRatio.y);
	else if (gameViewSize.x <= WINDOW_WIDTH / 4 || gameViewSize.y <= WINDOW_HEIGHT / 4)
		gameView->setSize(WINDOW_WIDTH / 4 + aspectRatio.x, WINDOW_HEIGHT / 4 + aspectRatio.y);
}

void Camera::keyPressed(sf::Event event, sf::Time deltaTime)
{
	if (event.type == sf::Event::MouseWheelMoved) {
		wheelDelta = event.mouseWheel.delta;
		if (wheelDelta > 0)	zoomTarget -= 0.5;
		else				zoomTarget += 0.5;
	}
}

void Camera::mapPixelToCoords(sf::RenderWindow& window)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	worldPos = window.mapPixelToCoords(pixelPos,*gameView);
}
