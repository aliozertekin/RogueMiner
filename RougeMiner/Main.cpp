#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "RougeMiner");
    Game::InitGame();
    Player player = Game::GetPlayer();
    
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        player.keyPressed();

        window.clear(sf::Color::White);

        player.playerAnimation();
        
        player.draw(window);

        window.display();
    }
}
