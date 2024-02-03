#pragma once
#include "Entities/Player.h"
#include "TextureManager.h"

class AnimationManager {
private:
	static void playerAnimation();
	static void selectorAnimation();
	static int selectorFrame;
	static sf::Sprite selectorSprite;
public:
	static void Initialize();
	static void Animate();
	static sf::Sprite getSelectorSprite();
	static void setSelectorSprite(sf::Sprite selector);
};