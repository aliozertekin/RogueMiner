#include "HealthBar.h"

HealthBar::HealthBar(int initialHealth) : health(initialHealth) {}

void HealthBar::update() {
    // Update logic for the health bar
}

void HealthBar::draw(sf::RenderWindow& window) {
    // Draw the health bar
    sf::RectangleShape healthBar(sf::Vector2f(health, 20));
    healthBar.setFillColor(sf::Color::Green);
    window.draw(healthBar);
}