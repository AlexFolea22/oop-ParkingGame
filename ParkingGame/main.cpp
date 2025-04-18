#include <iostream>
#include <SFML/Graphics.hpp>
#include "car.h"
#include "map_boundary.h"
#include "collider.h"
#include "actor.h"

int main()
{
    unsigned int width = 1920;
    unsigned int height = 1080;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({ width, height }), "Parking Game");
    window.setFramerateLimit(60);

    // Create the obstacle cube
    sf::RectangleShape cubShape({ 100.0f, 100.0f });
    cubShape.setPosition({ width / 2.0f, height / 4.0f });
    cubShape.setFillColor(sf::Color::Red); // Make it visible
    cubShape.setOrigin({ 50.0f, 50.0f }); // Set origin to center for consistent collision
    Collider cub(cubShape);

    // Create the car
    Car car("Sprites/Car.png", width / 2.0f, height / 2.0f, 64, 128, 1.0f, "player");

    // Previous positions to reset to after collision
    sf::Vector2f previousPosition;
    float previousRotation;

    // Game loop
    sf::Clock clock;
    while (window.isOpen()) {
        // Store previous state before movement
        previousPosition = car.getRectangle().getPosition();
        previousRotation = car.getRectangle().getRotation().asDegrees();

        // Handle events
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

        // Update car position based on input
        car.handleInput();

        // Check for collision
        if (cub.checkCollision(car.getCollider())) {
            std::cout << "Collision detected!" << std::endl;

            // Restore previous position
            car.getRectangle().setPosition(previousPosition);
            car.getRectangle().setRotation(sf::degrees(previousRotation));

            // Reset velocity to prevent continued movement
            car.setVelocity({ 0.0f, 0.0f });

            // Update the collider to match the restored position
            car.updateCollider();
        }

        // Render
        window.clear();
        window.draw(car.getRectangle());
        window.draw(cubShape); // Draw the obstacle

        // Draw collider visualizations for debugging
        car.drawCollider(window);
        cub.drawCollider(window);

        window.display();
    }

    return 0;
}