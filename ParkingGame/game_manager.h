#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "car.h"
#include "map_boundary.h"
#include "parked_cars.h"
#include "parking_spot.h"
#include "human.h"

class GameManager {

private:
	int m_width;
	int m_height;
	bool m_shouldClose;
	Actor m_floor;
	ParkingSpot m_spot;
	MapBoundary m_map;
	ParkedCars m_cars;
	Car m_car;
	static int m_checkpark;

	sf::Vector2f m_gameMapDimensions;
	std::vector<Human*> m_humans;


	sf::Vector2f m_previousPosition;
	float m_previousRotation;

	static sf::Clock m_gameTimerClock;
	static bool m_timerHasStarted;

	void initializeGameObjects();
	void checkCollisions();
	void checkParking();
	void resetCar();

public:
	GameManager(int width, int height);
	bool handleEvent(const sf::Event& event);
	void update(float dt);
	Car& getCar();
	MapBoundary& getMapBoundary();
	ParkedCars& getParkedCars();
	ParkingSpot& getParkingSpot();
	Actor& getFloor();
	bool shouldClose() const;

	const std::vector<Human*>& getHumans() const;


	static void startGameTimer();
	static sf::Time getTime();
	static bool isTimeRunning();

};


#endif //GAME_MANAGER
