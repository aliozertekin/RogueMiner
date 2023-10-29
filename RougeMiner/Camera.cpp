#include "Camera.h"
#include <iostream>
#include "Utils.h"

sf::View* Camera::gameView;
sf::View* Camera::hudView;
float Camera::zoomLevel;
float Camera::zoomTarget;

void Camera::setViews(sf::View* gameView, sf::View* hudView)
{
	Camera::gameView = gameView;
	Camera::hudView = hudView;
	zoomLevel = 0.0;
	zoomTarget = 0.0;
}

void Camera::Tick()
{
	float prevZoomLevel = zoomLevel;
	zoomLevel = Utils::lerp(zoomLevel, zoomTarget, 0.1);
	if(zoomLevel != 0) setZoomLevel((zoomLevel-prevZoomLevel)+1);
}

void Camera::setZoomLevel(float zoom)
{
	if (gameView == nullptr) return;
	gameView->zoom(zoom);
}

void Camera::keyPressed(sf::Event event, sf::Time deltaTime)
{
	if (event.type == sf::Event::MouseWheelMoved) {
		int wheelDelta = event.mouseWheel.delta;
		if (wheelDelta > 0)	zoomTarget -= 0.5;
		else				zoomTarget += 0.5;

		if (zoomTarget > 1.5) zoomTarget = 1.5;
		if (zoomTarget < -1.5) zoomTarget = -1.5;
	}
}
