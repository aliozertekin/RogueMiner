#include "Chunk.h"

Chunk::Chunk()
{
}

Chunk::Chunk(int x, int y)
{
    posX = x;
    posY = y;

    debugShape.setPosition(x*512.0, y*512.0);
    debugShape.setSize(sf::Vector2f(512.0, 512.0));
    debugShape.setFillColor(sf::Color::Transparent);
    debugShape.setOutlineThickness(2.0);
    debugShape.setOutlineColor(sf::Color::Red);
}

void Chunk::Draw(sf::RenderWindow& window)
{
    int xLen = sizeof(tiles) / (sizeof(Tile)*16);
    for (int x = 0; x < xLen; x++) {
        int yLen = sizeof(tiles[x]) / sizeof(Tile);
        for (int y = 0; y < yLen; y++) {
            tiles[x][y].Draw(window);
        }
    }
}

void Chunk::DebugDraw(sf::RenderWindow& window) {
    window.draw(debugShape);
}

Tile* Chunk::getTileAt(int x, int y) {
    return &tiles[x][y];
}

void Chunk::setTileAt(int x, int y, Tile tile) {
    tiles[x][y] = tile;
}

sf::Vector2f Chunk::tileToWorldCoordinates(int x, int y)
{
    float xPosition = (posX * 512.0) + x * 32.0;
    float yPosition = (posY * 512.0) + y * 32.0;
    return sf::Vector2f(xPosition, yPosition);
}
