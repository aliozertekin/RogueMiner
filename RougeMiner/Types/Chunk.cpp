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

sf::Vector2i Chunk::getChunkPos(Chunk* chunk)
{
    return sf::Vector2i(chunk->posX, chunk->posY);
}

sf::Vector2i Chunk::getChunkPos()
{
    return sf::Vector2i(this->posX, this->posY);
}

Tile* Chunk::getTileAt(int x, int y) {
    if (x < 0) x += 16;
    if (y < 0) y += 16;

    return &tiles[x][y];
}

Tile* Chunk::getTileAt(sf::Vector2i pos)
{
    if (pos.x < 0) pos.x = abs(pos.x + 15);
    if (pos.y < 0) pos.y = abs(pos.y + 15);

    return &tiles[pos.x][pos.y];
}

void Chunk::setTileAt(int x, int y, TileBase* tile) {
    if (x < 0) x = abs(x + 15);
    if (y < 0) y = abs(y + 15);

    tiles[x][y].SetType(tile);
}

void Chunk::setTileAt(int x, int y, Tile tile) {
    if (x < 0) x = abs(x + 15);
    if (y < 0) y = abs(y + 15);

    tiles[x][y] = tile;
}

sf::Vector2f Chunk::tileToWorldCoordinates(int x, int y)
{
    float xPosition = (posX * 512.0) + x * 32.0;
    float yPosition = (posY * 512.0) + y * 32.0;
    return sf::Vector2f(xPosition, yPosition);
}

sf::Vector2f Chunk::tileToWorldCoordinates(sf::Vector2f pos)
{
    float xPosition = (posX * 512.0) + pos.x * 32.0;
    float yPosition = (posY * 512.0) + pos.y * 32.0;
    return sf::Vector2f(xPosition, yPosition);
}

sf::Vector2f Chunk::tileToWorldCoordinates(sf::Vector2i pos)
{
    float xPosition = (posX * 512.0) + pos.x * 32.0;
    float yPosition = (posY * 512.0) + pos.y * 32.0;
    return sf::Vector2f(xPosition, yPosition);
}



