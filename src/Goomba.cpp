#include "headers/Goomba.h"

namespace mario
{

Goomba::Goomba()
    : m_velocity(0.0f, 0.0f), m_position(300, 200), m_currentAnimation(GoombaAnimations::Walking)
{
    m_animations[int(GoombaAnimations::Walking)] =
        Animation(0, 0, 30, 30, 2, "resources/smb_enemies_sheet.png");
    m_animations[int(GoombaAnimations::Dead)] =
        Animation(0, 62, 30, 30, 1, "resources/smb_enemies_sheet.png");

    m_goomba.setScale(SCALE_X, SCALE_Y);
    m_goomba.setPosition(m_position);
}

void Goomba::update(float deltaTime)
{
    m_position += m_velocity * deltaTime;

    m_animations[int(m_currentAnimation)].update(deltaTime);
    m_animations[int(m_currentAnimation)].applyToSprite(m_goomba);
}

void Goomba::setDirection(const sf::Vector2f &direction)
{
    m_velocity = direction * SPEED;
}

void Goomba::render(sf::RenderWindow &window)
{
    m_goomba.setPosition(m_position);
    window.draw(m_goomba);
}

} // namespace mario
