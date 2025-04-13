#include "Car.h"
#include <SFML/Window/Keyboard.hpp>

Car::Car(const std::string& textureName, float x, float y, int sizeX, int sizeY, float speed, const std::string& type)
    : Actor(textureName, x, y, sizeX, sizeY, type), speed(speed) {
    sprite.setOrigin(sf::Vector2f(sizeX / 2.0f, sizeY / 2.0f));
}

void Car::update(float deltaTime) {

}

void Car::handleInput() {

    float rotation = sprite.getRotation().asRadians();
    sf::Vector2f direction(std::sin(rotation), -std::cos(rotation));

    bool isAccelerating = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
        velocity += direction * acceleration;
        isAccelerating = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
        velocity.x -= 0.75*direction.x * acceleration;
        velocity.y -= 0.75*direction.y * acceleration;
        isAccelerating = true;
    }


	if (abs(velocity.x)>0.05f||abs(velocity.y)>0.05f) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            sprite.rotate(sf::degrees(-2));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            sprite.rotate(sf::degrees(2));
        }
	}

    // Apply friction if not accelerating
    if (!isAccelerating) {
        velocity.x *= (1.f - 0.4f * friction);
        velocity.y *= (1.f - 0.4f * friction);
    }

    //max speed
    float magnitude = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (magnitude > maxSpeed) {
        velocity = (velocity / magnitude) * maxSpeed;
    }

    sprite.move(velocity);
}
