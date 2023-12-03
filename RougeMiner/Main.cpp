#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main() {
    clock_t tStart = clock();
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "RogueMiner");
    
    Game::InitGame();
    Player player = Game::GetPlayer();
    
    window.setFramerateLimit(144);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            Game::EventHandler(event);
        }

        Game::Tick();
        window.clear(sf::Color::White);
        Game::Draw(window);
        window.display();
    }
}
