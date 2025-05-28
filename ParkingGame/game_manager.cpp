#include "game_manager.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const sf::Time& time) {
	float seconds = time.asSeconds();
	os << "AI PARCAT BOSS! Timp: "
		<< std::fixed << std::setprecision(2)
		<< seconds << " secunde";
	return os;
}



GameManager::GameManager(int width, int height) :
	m_width(width),
	m_height(height),
	m_shouldClose(false),
	m_floor("Sprites/Asphalt.png", 0.0f, 0.0f, 1920, 1080, "floor"),
	m_spot(1774, 563),
	m_map(1920.0f, 1080.0f, 38.0f),
	m_car("Sprites/Car.png", width / 6.6f, height / 1.2f, 64, 128, 1.0f, "player"),
	m_gameMapDimensions(static_cast<float>(width), static_cast<float>(height))
{
	initializeGameObjects();
}


sf::Clock GameManager::m_gameTimerClock;
bool GameManager::m_timerHasStarted = false;

void GameManager::initializeGameObjects() {

	m_previousPosition = m_car.getRectangle().getPosition();
	m_previousRotation = m_car.getRectangle().getRotation().asDegrees();

	if (!GameManager::isTimeRunning()) {
		GameManager::startGameTimer();
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> numHumansDist(5, 10);
	int numberOfHumans = numHumansDist(gen);
	std::cout << "GameManager: Spawning" << numberOfHumans;

	float padding = 5.0f;
	std::uniform_real_distribution<float> distX(padding, m_gameMapDimensions.x - padding);
	std::uniform_real_distribution<float> distY(padding, m_gameMapDimensions.y - padding);

	sf::Vector2f humanDefaultSize(30.f, 40.f);
	float humanDefaultSpeed = 60.f;

	m_humans.clear();

	for (int i = 0; i < numberOfHumans; i++) {
		sf::Vector2f randomPosition(distX(gen), distY(gen));
		Human* newHuman = new Human(
			randomPosition,
			m_gameMapDimensions,
			humanDefaultSpeed,
			humanDefaultSize
		);
		m_humans.push_back(newHuman);
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

void GameManager::update(float dt) {
	if (m_shouldClose == true) {
		return;
	}
	m_previousPosition = m_car.getRectangle().getPosition();
	m_previousRotation = m_car.getRectangle().getRotation().asDegrees();
	m_car.handleInput();

	for (auto& human_ptr : m_humans) {
		if (human_ptr) { 
			human_ptr->update(dt); 
		}
	}

	checkCollisions();
	checkParking();
}

void GameManager::checkCollisions() {
	bool carHitSomething = false;

	if (m_map.checkCollisions(m_car.getCollider()) ||
		m_cars.checkCollisions(m_car.getCollider())) {
		carHitSomething = true;
	}
	for (auto it = m_humans.begin(); it != m_humans.end();) {
		Human* current_human_ptr = *it;

		if (current_human_ptr) { 
			if (!carHitSomething && m_car.getCollider().checkCollision(*current_human_ptr)) { 
				delete current_human_ptr;
				it = m_humans.erase(it);
				carHitSomething = true; 
				break;
			}
			else {
				++it;
			}
		}
		else {
			it = m_humans.erase(it);
		}
	}

	if (carHitSomething) {
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

	/*sf::Time elapsedTime = GameManager::getTime();
	int seconds = elapsedTime.asSeconds();
	if(seconds%2==1){ 
		m_car.boostPhysics(-1); 
	}
	else {
		m_car.boostPhysics(1);
	}*/
}

int GameManager::m_checkpark = 0;

void GameManager::checkParking() {
	if (m_spot.IsParked(m_car)) {
		m_checkpark += 1;
		m_spot.getRectangle().setFillColor(sf::Color(255, 0, 0, 100));
		sf::Time elapsedTime = GameManager::getTime();
		float seconds = elapsedTime.asSeconds();
		if (m_checkpark == 1) {
			std::cout << elapsedTime << "\n";
		}
		}
	else {
		m_spot.getRectangle().setFillColor(sf::Color::Transparent);
	}
}

bool GameManager::shouldClose() const {
	return m_shouldClose;
}

void GameManager::startGameTimer() {
	m_gameTimerClock.restart();
	m_timerHasStarted = true;
}

sf::Time GameManager::getTime() { 
	if (m_timerHasStarted) {
		return m_gameTimerClock.getElapsedTime();
	}
	return sf::Time::Zero; 
}

bool GameManager::isTimeRunning() { 
	return m_timerHasStarted;
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
const std::vector<Human*>& GameManager::getHumans() const {
	return m_humans;
}


