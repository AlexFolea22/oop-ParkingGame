#include <iostream>
#include <SFML/Graphics.hpp>
#include "Car.h"

int main()
{
    unsigned int width = 1920;
    unsigned int height = 1080;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width, height }), "Parking Game");
    window->setFramerateLimit(60);
    Car car("Sprites/Car.png", width / 2.0f, height / 2.0f, 64, 128, 3.0f, "player");
    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window->close();
                }
            }
        }

        car.handleInput();

        // Render
        window->clear();

        // Drawing
        window->draw(car.getSprite());

        window->display();
    }

    return 0;
}