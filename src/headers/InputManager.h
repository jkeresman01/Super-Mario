#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

namespace mario
{

class InputManager
{
  public:
    InputManager();
    ~InputManager();

    bool isSpriteClicked(sf::Sprite &sprite, sf::Mouse::Button &button,
                         sf::RenderWindow &window) const;

    bool isMousePressed(sf::Mouse::Button &button) const;

    sf::Vector2i getMousePosition(sf::RenderWindow &window) const;
};

} // namespace mario
