#pragma once
#include <SFML/Graphics.hpp>
#include "Classes/ClassManager.h"
#include "../ChunkManager.h"
#include "../TileManager.h"

constexpr auto SPRITE_WIDTH = 48;
constexpr auto SPRITE_HEIGHT = 48;
 
class Player {
public:
	Player();
	void TileLook();
	void SetTexture(sf::Texture texture);
	void draw(sf::RenderWindow&);
	static std::unique_ptr<Player> createPlayer(ClassBase base);

	void breakTile();
	void placeBlock();

	Chunk* getChunkLookedAt();
	Tile* getTileLookedAt();
	Chunk* getOnChunk();
	Tile* getOnTile();
	Chunk* getMouseChunk();
	Tile* getMouseTile();

	void keyPressed(sf::Time deltaTime);
	sf::Vector2f getPos();

	enum playerStates {
		Idle,
		Running
	};
	enum playerDirections {
		Down,
		Left,
		Right,
		Up
	};
	

	static sf::Texture playerSheet;
	static sf::Sprite playerSprite;

	static int playerState;
	static int playerFrame;
	static int playerDirection;
	static int shownFPS;
	
	static sf::Clock spriteClock;
	static sf::Time spriteTime;

private:

	sf::Vector2f playerSpeed = sf::Vector2f(xSpeed,ySpeed);

	static Tile* targetTile;
	static Tile* onTile;
	static Chunk* targetChunk;
	static Chunk* onChunk;
	static Tile* mouseTile;

	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	float movementSpeed = 80.0f;
	float friction = 0.90f;
	int health;
	int stamina;
};