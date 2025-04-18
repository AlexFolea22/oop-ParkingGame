//#include "map_boundary.h"
//#include<iostream>
//
//MapBoundary::MapBoundary(float mapWidth, float mapHeight, float thickness)
//{
//	sf::RectangleShape topwall(sf::Vector2f(mapWidth, thickness));
//	topwall.setPosition({ 0, 0 });
//	m_walls.push_back(topwall);
//	m_colliders.emplace_back(topwall);
//
//	sf::RectangleShape bottomwall(sf::Vector2f(mapWidth, thickness));
//	bottomwall.setPosition({ 0,mapHeight - thickness });
//	m_walls.push_back(bottomwall);
//	m_colliders.emplace_back(bottomwall);
//
//	sf::RectangleShape leftwall(sf::Vector2f(thickness,mapHeight));
//	leftwall.setPosition({ 0,0 });
//	m_walls.push_back(leftwall);
//	m_colliders.emplace_back(leftwall);
//	
//	sf::RectangleShape rightwall(sf::Vector2f(thickness, mapHeight));
//	rightwall.setPosition({mapWidth - thickness,0 });
//	m_walls.push_back(rightwall);
//	m_colliders.emplace_back(rightwall);
//
//
//}
//
//void MapBoundary::checkCollisions(Collider& other, float push) {
//	for (Collider& wallcollider :m_colliders) {
//		other.checkCollision(wallcollider,push);
//	}
//}
//
//void MapBoundary::draw(sf::RenderWindow& window) {
//	for (sf::RectangleShape& wall : m_walls) {
//		window.draw(wall);
//	}
//}
//
