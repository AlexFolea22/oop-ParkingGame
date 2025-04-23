#pragma once
#ifndef PARKED_CARS_H
#define PARKED_CARS_H
#include "collider.h"

class ParkedCars {

private:
	std::vector<Collider>m_cars;
public:
	ParkedCars();
	bool checkCollisions(const Collider& other) const;
	virtual void draw(sf::RenderWindow& window);
};

#endif // !PARKED_CARS_H
