#include "headers/Mario.h"
#include "headers/ResourceManager.h"

namespace mario
{

Mario::Mario() : m_velocity(0.0f, 0.0f), m_position(400, 300)
{
    m_mario.setTexture(
        mario::ResourceManager::Instance().getTexture("resources/smb_mario_sheet.png"));
    m_mario.setScale(2, 2);
    // first + 30 to move right, rest is okey, start from 50
    m_mario.setTextureRect({230, 52, 29, 29});
    m_mario.setPosition(m_position);
}

void Mario::update(float deltaTime)
{
    m_position += m_velocity * deltaTime;
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
