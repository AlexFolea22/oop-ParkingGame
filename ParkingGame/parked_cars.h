#pragma once
#ifndef PARKED_CARS_H
#define PARKED_CARS_H
#include "collider.h"
#include "is_drawable.h"

class ParkedCars : public IsDrawable {

private:
	std::vector<Collider>m_cars;
public:
	ParkedCars();
	bool checkCollisions(const Collider& other) const;
	virtual void draw(sf::RenderWindow& window)const override;
};

#endif // !PARKED_CARS_H
