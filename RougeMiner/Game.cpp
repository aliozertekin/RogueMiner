#include "Entities/Classes/ClassManager.h"
#include "Game.h"
#include <map>
#define DEBUG true

Player Game::player;
sf::Clock Game::DeltaClock;
sf::Time Game::deltaTime;
sf::View Game::gameView;

void Game::InitGame()
{
	
	AnimationManager::Initialize();
	player.createPlayer(Barbarian());
	Utils::SetSeed(34634634);
	TextureManager::LoadTextures();
	Camera::setViews(&gameView, Hud::getView());
	player.SetTexture(TextureManager::playerTexture);
	ChunkManager::setTileSheet(TextureManager::tileTexture);
	TileManager::RegisterTiles();
	
	ChunkManager::InitChunks();
	gameView.setSize(static_cast<float>(WINDOW_WIDTH / 2), static_cast<float>(WINDOW_HEIGHT / 2));
	Hud::Init(gameView.getSize().x, gameView.getSize().y);
}

void Game::EventHandler(sf::Event& event) {
	Camera::keyPressed(event, Game::deltaTime);

	if(event.MouseButtonPressed){
		player.breakTile();
		player.placeBlock();
	}
}

void Game::Tick() {
	player.keyPressed(Game::deltaTime);


	Camera::Tick();
	Hud::Update();
	
}

void Game::Draw(sf::RenderWindow& window) {
	DrawView(window);
	Camera::mapPixelToCoords(window);
	AnimationManager::Animate();

	std::unordered_map<int, std::unordered_map<int, Chunk>>* chunks = ChunkManager::getChunks();

	for (auto& xPair : *chunks) {
		int xPos = xPair.first; // X coordinate

		auto& yMap = xPair.second;
		for (auto& yPair : yMap) {
			int yPos = yPair.first; // Y coordinate
			Chunk& chunk = yPair.second; // Chunk
			chunk.Draw(window);
			
			#ifdef DEBUG 
			chunk.DebugDraw(window);
			#endif
		}
	}

	

	player.draw(window);

	//player tile looked at selector
	player.TileLook();
	sf::Sprite selector = AnimationManager::getSelectorSprite();
	selector.setPosition(player.getChunkLookedAt()->tileToWorldCoordinates(player.getTileLookedAt()->GetPos()));


	//player tile selector
	sf::Sprite selector2 = AnimationManager::getSelectorSprite();
	selector2.setPosition(player.getOnChunk()->tileToWorldCoordinates(player.getOnTile()->GetPos()));
	selector2.setColor(sf::Color::Green);


	//mouse selector
	sf::Sprite selector3 = AnimationManager::getSelectorSprite();
	selector3.setPosition(ChunkManager::getChunkWorld(Camera::getGameViewMousePos())->tileToWorldCoordinates(ChunkManager::worldToTileCoordinates(Camera::getGameViewMousePos())->GetPos()));
	//selector3.setPosition(ChunkManager::worldToTileCoordinates(Camera::getGameViewMousePos())->tileToWorld());
	selector3.setColor(sf::Color::Blue);

	window.draw(selector2);
	window.draw(selector3);
	window.draw(selector);

	Hud::Draw(window);
	

	
	deltaTime = DeltaClock.restart();
}

void Game::DrawView(sf::RenderWindow& window)
{
	gameView.setCenter(player.getPos());
	window.setView(gameView);
}

Player Game::GetPlayer()
{
	return player;
}
