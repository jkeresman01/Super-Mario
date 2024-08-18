#include "headers/Mario.h"

namespace mario
{

Mario::Mario()
    : m_velocity(0.0f, 0.0f), m_position(400, 300),
      m_walkingAnimantion(230, 52, 29, 29, 3, "resources/smb_mario_sheet.png")
{
    m_mario.setScale(2, 2);
    m_mario.setPosition(m_position);
}

void Mario::update(float deltaTime)
{
    m_position += m_velocity * deltaTime;
    m_walkingAnimantion.update(deltaTime);
    m_walkingAnimantion.applyToSprite(m_mario);
}

void Mario::setDirection(const sf::Vector2f &direction)
{
    m_velocity = direction * SPEED;
}

void Mario::render(sf::RenderWindow &window)
{
    m_mario.setPosition(m_position);
    window.draw(m_mario);
}

} // namespace mario
