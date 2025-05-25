#include "game_manager.h"
GameManager::GameManager(int width, int height) :
	m_width(width),
	m_height(height),
	m_shouldClose(false),
	m_floor("Sprites/Asphalt.png", 0.0f, 0.0f, 1920, 1080, "floor"),
	m_spot(1774, 563),
	/*m_cubShape({ 450.0f, 100.0f }),
	m_cub(m_cubShape),*/
	m_map(1920.0f, 1080.0f, 38.0f),
	m_car("Sprites/Car.png", width / 6.6f, height / 1.2f, 64, 128, 1.0f, "player")
{
	initializeGameObjects();
}

void GameManager::initializeGameObjects() {
	/*m_cubShape.setSize({ 450.0f, 100.0f });
	m_cubShape.setPosition({ 110.0f, 1035.0f });
	m_cubShape.setFillColor(sf::Color::Transparent);
	m_cubShape.setOrigin({ 50.0f, 50.0f });*/




	m_previousPosition = m_car.getRectangle().getPosition();
	m_previousRotation = m_car.getRectangle().getRotation().asDegrees();
}

bool GameManager::handleEvent(const sf::Event& event) {
	if (event.is<sf::Event::Closed>()) {
		m_shouldClose = true;
		return false;
	}
	else if(const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()){
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
			m_shouldClose = true;
			return false;
		}
	}
	return true;
}

void GameManager::update() {
	if (m_shouldClose == true) {
		return;
	}
	m_previousPosition = m_car.getRectangle().getPosition();
	m_previousRotation = m_car.getRectangle().getRotation().asDegrees();
	m_car.handleInput();
	checkCollisions();
	checkParking();
}

void GameManager::checkCollisions() {
	if (/*m_cub.checkCollision(m_car.getCollider()) ||*/
		m_map.checkCollisions(m_car.getCollider()) ||
		m_cars.checkCollisions(m_car.getCollider())) {
		resetCar();
	}
}
void GameManager::resetCar() {

	m_car.getRectangle().setPosition(m_previousPosition);
	m_car.getRectangle().setRotation(sf::degrees(m_previousRotation));

	//RESETEAZA MASINA
	/*m_car.getRectangle().setPosition({ m_width / 6.6f, m_height / 1.2f });
	m_car.getRectangle().setRotation(sf::degrees(0));*/
	m_car.setVelocity({ 0.0f, 0.0f });
	m_car.updateCollider();
}

void GameManager::checkParking() {
	if (m_spot.IsParked(m_car)) {
		/*std::cout << "AI PARCAT BOSS\n";*/
		m_spot.getRectangle().setFillColor(sf::Color(255, 0, 0, 100));
	}
	else {
		m_spot.getRectangle().setFillColor(sf::Color::Transparent);
	}
}

bool GameManager::shouldClose() const {
	return m_shouldClose;
}

Car& GameManager::getCar() { return m_car; }
MapBoundary& GameManager::getMapBoundary() { return m_map; }
ParkedCars& GameManager::getParkedCars() { return m_cars; }
ParkingSpot& GameManager::getParkingSpot() { return m_spot; }
Actor& GameManager::getFloor() { return m_floor; }
//sf::RectangleShape& GameManager::getCubShape() { return m_cubShape; }

