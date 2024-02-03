#include "Hud.h"
#include "HealthBar.h"

sf::View Hud::hudView;
std::map<std::string, std::unique_ptr<HudElement>> Hud::elements;

void Hud::Init(float windowW, float windowH)
{
	hudView.setSize(windowW, windowH);
	hudView.setCenter(sf::Vector2f(0,0));
	AddElement("HealthBar", std::make_unique<HealthBar>(100));
}

void Hud::Draw(sf::RenderWindow& window)
{
	window.setView(hudView);
	for (auto& pair : elements) {
		pair.second->draw(window);
	}
}

void Hud::AddElement(const std::string& name, std::unique_ptr<HudElement> element)
{
	elements[name] = std::move(element);
}

void Hud::Update()
{
	for (auto& pair : elements) {
		pair.second->update();
	}
}

sf::View* Hud::getView()
{
	return &hudView;
}