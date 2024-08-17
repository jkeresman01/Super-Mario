#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>

namespace mario
{
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

    static constexpr float SPEED = 100.0f;
};

class Animation
{
  public:
    Animation(int32_t positionX, int32_t positionYi, int32_t width, int32_t height,
              const std::filesystem::path &filepath);

  private:
    static constexpr int32_t NUMBER_OF_FRAMES = 7;
    static constexpr float HOLD_TIME          = 0.1f;

    sf::Texture m_texture;
    sf::IntRect m_frames[NUMBER_OF_FRAMES];
    int32_t m_currentFrame = 0;
    float m_elapsedTime;
};

} // namespace mario
