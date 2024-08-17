#include "headers/Mario.h"
#include "headers/ResourceManager.h"

namespace mario
{

Animation::Animation(uint32_t positionX, uint32_t positionY, uint32_t width, uint32_t height,
              const std::filesystem::path &filepath)
{
    m_texture = ResourceManager::Instance().getTexture(filepath);

    for(uint32_t i = 0; i < NUMBER_OF_FRAMES; ++i)
    {
            m_frames[i] = sf::IntRect(positionX + i * width, positionY , width, height);
    }
}

void Animation::update(float deltaTime)
{
    m_elapsedTime += deltaTime;

    while(m_elapsedTime >= HOLD_TIME)
    {
        m_elapsedTime -= HOLD_TIME;

        if(++m_currentFrame >= NUMBER_OF_FRAMES)
        {
            m_currentFrame = 0;
        }
    }
}

void Animation::applyToSprite(sf::Sprite &sprite) const
{
    sprite.setTexture(m_texture);
    sprite.setTextureRect(m_frames[m_currentFrame]);
}


Mario::Mario() : m_velocity(0.0f, 0.0f), m_position(400, 300),
    m_walkingAnimantion(230, 52, 29, 29, "resources/smb_mario_sheet.png")
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
