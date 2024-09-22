#include "headers/InputManager.h"

namespace mario
{

bool InputManager::isSpriteClicked(sf::Sprite &sprite, sf::Mouse::Button &button,
                                   sf::RenderWindow &window) const
{
    auto spritePosition = sprite.getPosition();
    auto spriteGlobalBounds = sprite.getGlobalBounds();

    sf::IntRect rect(spritePosition.x, spritePosition.y, spriteGlobalBounds.width,
                     spriteGlobalBounds.height);

    auto mousePosition = getMousePosition(window);
    bool isMouseOnSprite = rect.contains(mousePosition);

    return isMousePressed(button) and isMouseOnSprite;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window) const
{
    return sf::Mouse::getPosition(window);
}

bool InputManager::isMousePressed(sf::Mouse::Button &button) const
{
    return sf::Mouse::isButtonPressed(button);
}

} // namespace mario
