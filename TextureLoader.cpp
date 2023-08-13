#include "TextureLoader.h"
#include <assert.h>

TextureLoader* TextureLoader::m_instace = nullptr;

TextureLoader::TextureLoader()
{
	assert(m_instace == nullptr);

	m_instace = this;
}

Texture& TextureLoader::getTexture(std::string const& filename)
{
	std::map<std::string, Texture>& mapTextures = m_instace->m_textures;

	std::map<std::string, Texture>::iterator stringTexturePair = mapTextures.find(filename);

	if (stringTexturePair == mapTextures.end())
	{
		Image image;
		image.loadFromFile(filename);
		image.createMaskFromColor(Color::Green);

		Texture& rNewTexture = mapTextures[filename];
		rNewTexture.loadFromImage(image);

		return rNewTexture;
	}
	else
	{
		return stringTexturePair->second;
	}
}