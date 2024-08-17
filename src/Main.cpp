#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "headers/Mario.h"
#include "headers/ResourceManager.h"

#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    mario::ResourceManager resourceManager;

    mario::Mario mario;

    auto start = std::chrono::steady_clock::now();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        auto end        = std::chrono::steady_clock::now();
        float deltaTime = std::chrono::duration<float>(end - start).count();
        start           = end;

        sf::Vector2f direction = {0.0f, 0.0f};

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            direction.y -= 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            direction.y += 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direction.x -= 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction.x += 1.0f;
        }

        mario.setDirection(direction);
        mario.update(deltaTime);

        window.clear();
        mario.render(window);
        window.display();
    }
}
