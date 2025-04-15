#include "collider.h"
#include <iostream>

Collider::Collider(sf::RectangleShape& body) : m_body(body) {
	body.setOrigin(body.getSize() / 2.0f);
}

sf::Vector2f Collider::getPosition() {
	return m_body.getPosition();
}
sf::Vector2f Collider::getHalfSize() {
	return m_body.getSize() / 2.0f;
}
void Collider::move(float dx, float dy) {
	m_body.move({ dx, dy });
}
bool Collider::checkCollision(Collider& other, float push) {

	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
	float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);
	std::cout << "  Intersect X: " << intersectX << ", Y: " << intersectY << std::endl;

	if (intersectX < 0.0f && intersectY < 0.0f) {
		std::cout << "  Collision detected!" << std::endl;

		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				move(intersectX * (1.0f-push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else {
				move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				move(0.0f,intersectY * (1.0f - push));
				other.move(0.0f,-intersectY * push);
			}
			else {
				move(0.0f,-intersectY * (1.0f - push));
				other.move(0.0f,intersectY * push);
			}
		}
		return true;
	}

	return false;
};

