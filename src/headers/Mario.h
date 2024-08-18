#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "Animation.h"

#include <filesystem>

namespace mario
{

enum class MarioAnimations
{
    RighWalk = 0,
    LeftWalk = 1,
    Count    = 2,
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
    MarioAnimations m_currentAnimation;
    Animation m_animations[int(MarioAnimations::Count)];

    static constexpr float SPEED = 100.0f;
};

} // namespace mario
