#include "Chunk.h"

Chunk::Chunk()
{
}

Chunk::Chunk(int x, int y)
{
    debugShape.setPosition(x*256.0, y*256.0);
    debugShape.setSize(sf::Vector2f(256.0, 256.0));
    debugShape.setFillColor(sf::Color::Transparent);
    debugShape.setOutlineThickness(2.0);
    debugShape.setOutlineColor(sf::Color::Red);
}

void Chunk::DebugDraw(sf::RenderWindow& window) {
    window.draw(debugShape);
}

Tile Chunk::getTileAt(int x, int y) {
    return tiles[x][y];
}

void Chunk::setTileAt(int x, int y, Tile tile) {
    tiles[x][y] = tile;
}
