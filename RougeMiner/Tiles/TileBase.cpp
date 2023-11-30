#include "TileBase.h"

void TileBase::Draw(sf::RenderWindow& window, sf::Sprite& sprite)
{
	if (this->flags & FLAGS::INVISIBLE) return;

	window.draw(sprite);
}
