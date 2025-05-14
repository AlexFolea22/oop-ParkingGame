#include <iostream>
#include <SFML/Graphics.hpp>
#include "car.h"
#include "map_boundary.h"
#include "collider.h"
#include "actor.h"
#include "parked_cars.h"
#include "parking_spot.h"

int main()
{
    unsigned int width = 1920;
    unsigned int height = 1080;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({ width, height }), "Parking Game");
    window.setFramerateLimit(60);

    Actor floor("Sprites/Asphalt.png",0.0f, 0.0f, 1920, 1080, "floor");

    ParkingSpot spot(1774, 563);

    sf::RectangleShape cubShape({ 450.0f, 100.0f });
    cubShape.setPosition({ 110.0f, 1035.0f });
    cubShape.setFillColor(sf::Color::Transparent);
    cubShape.setOrigin({ 50.0f, 50.0f }); 
    Collider cub(cubShape);

    MapBoundary map(1920.0f, 1080.0f, 38.0f);
    ParkedCars cars;


    Car car("Sprites/Car.png", width / 6.6f, height / 1.2f, 64, 128, 1.0f, "player");


    sf::Vector2f previousPosition;
    float previousRotation;

    // Game loop
    sf::Clock clock;
    while (window.isOpen()) {
        previousPosition = car.getRectangle().getPosition();
        previousRotation = car.getRectangle().getRotation().asDegrees();

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

        //collision
        if (cub.checkCollision(car.getCollider())||map.checkCollisions(car.getCollider())||cars.checkCollisions(car.getCollider())) {

            car.getRectangle().setPosition(previousPosition);
            car.getRectangle().setRotation(sf::degrees(previousRotation));


            //RESET

            car.getRectangle().setPosition({ width / 6.6f, height / 1.2f });
            car.getRectangle().setRotation(sf::degrees(0));

            car.setVelocity({ 0.0f, 0.0f });
            car.updateCollider();
        }
       map.checkCollisions(car.getCollider());

       //parkingcheck

       if (spot.IsParked(car))
       {
           std::cout << "AI PARCAT BOSS";
           spot.getRectangle().setFillColor(sf::Color (255, 0, 0, 100));
        }
       else {
           spot.getRectangle().setFillColor(sf::Color::Transparent);
       }

      
        // Render
        window.clear();
        floor.draw(window);
        window.draw(car.getRectangle());
        window.draw(cubShape);
        map.draw(window);
        cars.draw(window);
        spot.draw(window);


        window.display();
    }

    return 0;
}


///game manager rendering, 