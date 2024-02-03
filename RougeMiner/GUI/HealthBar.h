#pragma once
#include "HudElement.h"

class HealthBar : public HudElement {
private:
    int health;
    sf::Sprite healthBar;
    sf::Texture currenthealth;
    sf::Texture currentHealth(int initialHP,int currentHP);

    sf::Texture hpBegin;
    sf::Texture hpMiddle;
    sf::Texture hpEnd;
public:
    HealthBar(int initialHealth);
    
    void update() override;
    void draw(sf::RenderWindow& window) override;
};