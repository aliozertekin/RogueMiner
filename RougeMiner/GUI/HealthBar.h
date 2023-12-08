#pragma once
#include "HudElement.h"

class HealthBar : public HudElement {
private:
    int health;

public:
    HealthBar(int initialHealth);

    void update() override;
    void draw(sf::RenderWindow& window) override;
};