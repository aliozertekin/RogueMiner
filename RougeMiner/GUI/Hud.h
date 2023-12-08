#pragma once
#include <SFML/Graphics.hpp>
#include "HudElement.h"

class Hud {
public:
	static void Init(float windowW, float windowH);
	static void Update();
	static void Draw(sf::RenderWindow&);
	static void AddElement(const std::string& name, std::unique_ptr<HudElement> element);

	static sf::View* getView();
private:
	static sf::View hudView;
	static std::map<std::string, std::unique_ptr<HudElement>> elements;
};