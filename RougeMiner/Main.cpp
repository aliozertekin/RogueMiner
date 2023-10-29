#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "RougeMiner");
    
    Game::InitGame();
    Player player = Game::GetPlayer();
    
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            Game::eventCalls(event);
        }
        Game::Tick();
        window.clear(sf::Color::White);
        Game::Draw(window);
        window.display();
    }
}
