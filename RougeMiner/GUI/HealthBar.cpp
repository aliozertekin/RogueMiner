#include "HealthBar.h"
#include "../TextureManager.h"

sf::Texture HealthBar::currentHealth(int initialHP, int currentHP)
{
    sf::Texture middle;
    if (1) {
        return hpBegin;
        
    }
    else {
        std::cout << "hpbegin did not create";
    }


}

HealthBar::HealthBar(int initialHealth) : health(initialHealth) {}

void HealthBar::update() {
    // Update logic for the health bar
  
}

void HealthBar::draw(sf::RenderWindow& window) {
    // Draw the health bar
   
   healthBar.setPosition(10, 10);
  healthBar.setTexture(currentHealth(5,5));
   
   window.draw(healthBar);
}