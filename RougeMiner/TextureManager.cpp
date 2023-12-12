#include "TextureManager.h"

sf::Texture TextureManager::playerTexture;
sf::Texture TextureManager::tileTexture;
std::map<std::string, sf::IntRect> TextureManager::textureRegistry;

void TextureManager::LoadTextures()
{
	if (!playerTexture.loadFromFile("Assets/entities/player.png")) {
		std::cout << "Couldn't load file 'Player.png'!";
	}

    tileTexture = StitchTextures("Assets/tiles");
}

sf::IntRect TextureManager::GetTextureRect(std::string id)
{
    return textureRegistry[id];
}

sf::Texture TextureManager::StitchTextures(const std::string& folderPath)
{
    sf::Texture resultTexture;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            sf::Texture texture;
            sf::Texture prevTexture = resultTexture;
            if (texture.loadFromFile(entry.path().string())) {
                std::string filename = entry.path().filename().string();

                sf::Vector2u textureSize = texture.getSize();
                sf::IntRect textureRect(resultTexture.getSize().x, 0, textureSize.x, textureSize.y);

                resultTexture.create(resultTexture.getSize().x + textureSize.x, std::max(resultTexture.getSize().y, textureSize.y));
                resultTexture.update(prevTexture, 0, 0);
                resultTexture.update(texture, textureRect.left, textureRect.top);

                filename.erase(filename.end() - 4, filename.end());
                textureRegistry[filename] = textureRect;
            }
            else {
                std::cerr << "Failed to load texture from file: " << entry.path() << std::endl;
            }
        }
    }

    return resultTexture;
}
