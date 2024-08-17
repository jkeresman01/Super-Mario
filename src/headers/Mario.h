#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>

namespace mario
{

class Animation
{
  public:
    Animation(uint32_t positionX, uint32_t positionY, uint32_t width, uint32_t height,
              const std::filesystem::path &filepath);

    void applyToSprite(sf::Sprite &sprite) const;

    void update(float deltaTime);

  private:
    static constexpr int32_t NUMBER_OF_FRAMES = 3;
    static constexpr float HOLD_TIME = 0.1f;

    sf::Texture m_texture;
    sf::IntRect m_frames[NUMBER_OF_FRAMES];
    int32_t m_currentFrame = 0;
    float m_elapsedTime;
};

class Mario
{
  public:
    Mario();

    void render(sf::RenderWindow &window);

    void update(float deltaTime);

    void setDirection(const sf::Vector2f &direction);

    sf::Vector2f getPosition() const { return m_position; }

  private:
    sf::Sprite m_mario;
    sf::Vector2f m_velocity;
    sf::Vector2f m_position;
    Animation m_walkingAnimantion;

    static constexpr float SPEED = 100.0f;
};

} // namespace mario
