#pragma once

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include <filesystem>
#include <unordered_map>

namespace mario
{

typedef std::unordered_map<std::string, sf::Font> FontMapT;
typedef std::unordered_map<std::string, sf::Texture> TextureMapT;
typedef std::unordered_map<std::string, sf::SoundBuffer> SoundBufferMapT;

class ResourceManager
{
  public:
    ResourceManager()                        = default;
    ResourceManager(const ResourceManager &) = delete;

    ResourceManager operator=(const ResourceManager &) = delete;

    static ResourceManager &Instance();

    const sf::Texture &getTexture(const std::filesystem::path &filepath);
    const sf::Font &getFont(const std::filesystem::path &filepath);
    const sf::SoundBuffer &getSoundBuffer(const std::filesystem::path &filepath);

  private:
    void loadFont(const std::filesystem::path &filepath);
    void loadTexture(const std::filesystem::path &filepath);
    void loadSoundBuffer(const std::filesystem::path &filepath);

  private:
    FontMapT m_fonts;
    TextureMapT m_textures;
    SoundBufferMapT m_soundBuffers;
};

} // namespace mario
