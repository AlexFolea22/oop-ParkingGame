#include <iostream>
#include <SFML/Graphics.hpp>
#include "car.h"
#include "map_boundary.h"

int main()
{
    unsigned int width = 1920;
    unsigned int height = 1080;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({ width, height }), "Parking Game");
    window.setFramerateLimit(60);

    sf::RectangleShape cub({ 50.0f, 50.0f });
    cub.setPosition({ width / 2.0f, height / 4.0f});
    Collider rect(cub);
    MapBoundary mapBoundary(1920, 1080,80.0f);
    Car car("Sprites/Car.png", width / 2.0f, height / 2.0f, 64, 128, 1.0f, "player");
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }



        car.handleInput();
        mapBoundary.checkCollisions(car.getCollider(),0.5f);
        rect.checkCollision(car.getCollider(), 0.5f);



        // Render
        window.clear();

        // Drawing
        window.draw(car.getRectangle());
        window.draw(cub);
        mapBoundary.draw(window);

        window.display();
    }

    return 0;
}