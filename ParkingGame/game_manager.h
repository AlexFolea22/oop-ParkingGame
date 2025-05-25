#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "car.h"
#include "map_boundary.h"
#include "collider.h"
#include "actor.h"
#include "parked_cars.h"
#include "parking_spot.h"

class GameManager {

private:
	int m_width;
	int m_height;
	bool m_shouldClose;
	Actor m_floor;
	ParkingSpot m_spot;
	/*sf::RectangleShape m_cubShape;*/
	/*Collider m_cub;*/
	MapBoundary m_map;
	ParkedCars m_cars;
	Car m_car;

	sf::Vector2f m_previousPosition;
	float m_previousRotation;

	void initializeGameObjects();
	void checkCollisions();
	void checkParking();
	void resetCar();

public:
	GameManager(int width, int height);
	bool handleEvent(const sf::Event& event);
	void update();
	Car& getCar();
	MapBoundary& getMapBoundary();
	ParkedCars& getParkedCars();
	ParkingSpot& getParkingSpot();
	Actor& getFloor();
	sf::RectangleShape& getCubShape();
	bool shouldClose() const;
};


#endif //GAME_MANAGER
