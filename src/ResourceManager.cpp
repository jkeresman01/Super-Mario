#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace mario
{

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    TextureMapT::iterator it = m_textures.find(filepath.string());

    if (it == m_textures.end())
    {
        loadTexture(filepath);
        it = m_textures.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadTexture(const std::filesystem::path &filepath)
{
    sf::Texture texture;

    bool isTextureLoadedSuccessfully = texture.loadFromFile(filepath);

    if (isTextureLoadedSuccessfully)
    {
        m_textures.emplace(filepath.string(), texture);
    }
    else
    {
        LOG_ERROR("Failed to load texture from " << filepath.string() << "!");
    }
}

const sf::Font &ResourceManager::getFont(const std::filesystem::path &filepath)
{
    FontMapT::iterator it = m_fonts.find(filepath.string());

    if (it == m_fonts.end())
    {
        loadFont(filepath);
        it = m_fonts.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadFont(const std::filesystem::path &filepath)
{
    sf::Font font;

    bool isFontLoadedSuccesfully = font.loadFromFile(filepath);

    if (isFontLoadedSuccesfully)
    {
        m_fonts.emplace(filepath.string(), font);
    }
    else
    {
        LOG_ERROR("Failed to load font from " << filepath.string() << "!");
    }
}

const sf::SoundBuffer &ResourceManager::getSoundBuffer(const std::filesystem::path &filepath)
{
    SoundBufferMapT::iterator it = m_soundBuffers.find(filepath.string());

    if (it == m_soundBuffers.end())
    {
        loadFont(filepath);
        it = m_soundBuffers.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadSoundBuffer(const std::filesystem::path &filepath)
{
    sf::SoundBuffer soundBuffer;

    bool isSoundBufferLoadedSuccesfully = soundBuffer.loadFromFile(filepath);

    if (isSoundBufferLoadedSuccesfully)
    {
        m_soundBuffers.emplace(filepath.string(), soundBuffer);
    }
    else
    {
        LOG_ERROR("Failed to load sound buffer from " << filepath.string() << "!");
    }
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instace;
    return instace;
}

} // namespace mario
