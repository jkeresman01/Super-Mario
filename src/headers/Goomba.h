#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>

#include "Animation.h"

namespace mario
{
enum class GoombaAnimations
{
    Alive   = 0,
    Dead    = 1,
    Count   = 2,
};

class Goomba
{
  public:
    Goomba();

    void render(sf::RenderWindow &window);

    void update(float deltaTime);

    void setDirection(const sf::Vector2f &direction);

    sf::Vector2f getPosition() const { return m_position; }

  private:
    sf::Sprite m_goomba;
    sf::Vector2f m_velocity;
    sf::Vector2f m_position;
    GoombaAnimations m_currentAnimation;
    Animation m_animations[int(GoombaAnimations::Count)];

    static constexpr float SPEED = 100.0f;

    static constexpr float SCALE_X = 2.0f;
    static constexpr float SCALE_Y = 2.0f;
};

} // namespace mario
