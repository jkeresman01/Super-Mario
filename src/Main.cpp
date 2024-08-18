#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "headers/Goomba.h"
#include "headers/Mario.h"
#include "headers/ResourceManager.h"

#include <SFML/Graphics/RectangleShape.hpp>

#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 480), "SFML Window");
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(960, 480));
    mario::ResourceManager resourceManager;

    mario::Mario mario;
    mario::Goomba goomba;

    auto start = std::chrono::steady_clock::now();

    sf::Vector2f direction = {0.0f, 0.0f};

    sf::Texture mapTexture;
    mapTexture.loadFromFile("resources/map.png");

    sf::Sprite map;
    map.setScale(2, 2);
    map.setTexture(mapTexture);

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

        auto end = std::chrono::steady_clock::now();

        float deltaTime = std::chrono::duration<float>(end - start).count();

        start = end;

        direction.x *= 0.5;

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

        goomba.setDirection(direction);
        goomba.update(deltaTime);

        view.setCenter(mario.getPosition().x, mario.getPosition().y);
        window.setView(view);

        window.clear();
        window.draw(map);
        mario.render(window);
        goomba.render(window);
        window.display();
    }
}
