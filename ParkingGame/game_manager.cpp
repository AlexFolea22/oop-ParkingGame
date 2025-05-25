#include "game_manager.h"
GameManager::GameManager(int width, int height) :
	m_width(width),
	m_height(height),
	m_shouldClose(false),
	m_floor("Sprites/Asphalt.png", 0.0f, 0.0f, 1920, 1080, "floor"),
	m_spot(1774, 563),
	m_map(1920.0f, 1080.0f, 38.0f),
	m_car("Sprites/Car.png", width / 6.6f, height / 1.2f, 64, 128, 1.0f, "player")
{
	initializeGameObjects();
}


sf::Clock GameManager::gameTimerClock;
bool GameManager::timerHasStarted = false;

void GameManager::initializeGameObjects() {

	m_previousPosition = m_car.getRectangle().getPosition();
	m_previousRotation = m_car.getRectangle().getRotation().asDegrees();

	if (!GameManager::isTimeRunning()) {
		GameManager::startGameTimer();
	}
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
	if (m_map.checkCollisions(m_car.getCollider()) ||
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
		m_spot.getRectangle().setFillColor(sf::Color(255, 0, 0, 100));
		sf::Time elapsedTime = GameManager::getTime();
		float seconds = elapsedTime.asSeconds();      
		std::cout << "AI PARCAT BOSS! Timp: " << seconds << " secunde\n";
	}
	else {
		m_spot.getRectangle().setFillColor(sf::Color::Transparent);
	}
}

bool GameManager::shouldClose() const {
	return m_shouldClose;
}

void GameManager::startGameTimer() {
	gameTimerClock.restart();
	timerHasStarted = true;
}

sf::Time GameManager::getTime() { 
	if (timerHasStarted) {
		return gameTimerClock.getElapsedTime();
	}
	return sf::Time::Zero; 
}

bool GameManager::isTimeRunning() { 
	return timerHasStarted;
}

Car& GameManager::getCar() { 
	return m_car; 
}
MapBoundary& GameManager::getMapBoundary() { 
	return m_map; 
}
ParkedCars& GameManager::getParkedCars() { 
	return m_cars; 
}
ParkingSpot& GameManager::getParkingSpot() { 
	return m_spot;
}
Actor& GameManager::getFloor() { 
	return m_floor;
}

