#include "parking_spot.h"
#include <iostream>



ParkingSpot::ParkingSpot(float x, float y) : Actor("parking_spot", x, y, 108, 170, "parking_spot")

{
	m_rectangle.setOrigin({ 0, 0 });
	m_rectangle.setOutlineColor(sf::Color::White);
	m_rectangle.setOutlineThickness(2.0f);
	m_rectangle.setFillColor(sf::Color(255, 255, 255, 100));
}




bool ParkingSpot::isPointInsideRect(const sf::Vector2f& point, const sf::RectangleShape& rect) const {

	const sf::Transform& transform = rect.getTransform();
	sf::Vector2f size = rect.getSize();
	sf::Vector2f origin = rect.getOrigin();
	sf::Vector2f localPoint = transform.getInverse().transformPoint(point);

	return (localPoint.x >= -origin.x &&
		localPoint.x <= (size.x - origin.x) &&
		localPoint.y >= -origin.y &&
		localPoint.y <= (size.y - origin.y));
}



std::array<sf::Vector2f, 4> ParkingSpot::getCorners(const sf::RectangleShape& rect) const {
	const sf::Transform& transform = rect.getTransform();
	sf::Vector2f size = rect.getSize();
	sf::Vector2f localTopLeft(0.0f, 0.0f);
	sf::Vector2f localTopRight(size.x, 0.0f);
	sf::Vector2f localBottomRight(size.x, size.y);
	sf::Vector2f localBottomLeft(0.0f, size.y);


	std::array<sf::Vector2f, 4> corners;
	corners[0] = transform.transformPoint(localTopLeft);
	corners[1] = transform.transformPoint(localTopRight);
	corners[2] = transform.transformPoint(localBottomRight);
	corners[3] = transform.transformPoint(localBottomLeft);

	return corners;
}


bool ParkingSpot::IsParked(const Actor& car) {

	std::array<sf::Vector2f, 4> carCorners = getCorners(car.getRectangle());
	int cornersInside = 0;
	for (const auto& corner : carCorners) {

		if (isPointInsideRect(corner, m_rectangle)) {
			cornersInside++;
		}
	}

	return cornersInside == 4;
}