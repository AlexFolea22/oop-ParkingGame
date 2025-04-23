#include "parked_cars.h"
ParkedCars::ParkedCars() {

	sf::RectangleShape car1(sf::Vector2f(128.0f, 64.0f));
	car1.setPosition({ 65.0f,711.0f });
	car1.setFillColor(sf::Color::Red);
	m_cars.emplace_back(car1);

    sf::RectangleShape car2(sf::Vector2f(128.0f, 64.0f));
    car2.setPosition({ 65.0f,604.0f });
    car2.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car2);

    sf::RectangleShape car3(sf::Vector2f(128.0f, 64.0f));
    car3.setPosition({ 65.0f,495.0f });
    car3.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car3);

    sf::RectangleShape car4(sf::Vector2f(128.0f, 64.0f));
    car4.setPosition({ 65.0f,386.0f });
    car4.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car4);

    sf::RectangleShape car5(sf::Vector2f(128.0f, 64.0f));
    car5.setPosition({ 65.0f,277.0f });
    car5.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car5);

    sf::RectangleShape car6(sf::Vector2f(128.0f, 64.0f));
    car6.setPosition({ 65.0f,168.0f });
    car6.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car6);


    sf::RectangleShape car7(sf::Vector2f(128.0f, 64.0f));
    car7.setPosition({ 520.0f,711.0f });
    car7.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car7);

    sf::RectangleShape car8(sf::Vector2f(128.0f, 64.0f));
    car8.setPosition({ 520.0f,604.0f });
    car8.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car8);

    sf::RectangleShape car9(sf::Vector2f(128.0f, 64.0f));
    car9.setPosition({ 520.0f,495.0f });
    car9.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car9);

    sf::RectangleShape car10(sf::Vector2f(128.0f, 64.0f));
    car10.setPosition({ 520.0f,386.0f });
    car10.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car10);

    sf::RectangleShape car11(sf::Vector2f(128.0f, 64.0f));
    car11.setPosition({ 520.0f,277.0f });
    car11.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car11);

    sf::RectangleShape car12(sf::Vector2f(128.0f, 64.0f));
    car12.setPosition({ 520.0f,818.0f });
    car12.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car12);



    sf::RectangleShape car13(sf::Vector2f(128.0f, 64.0f));
    car13.setPosition({ 855.0f,711.0f });
    car13.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car13);

    sf::RectangleShape car14(sf::Vector2f(128.0f, 64.0f));
    car14.setPosition({ 855.0f,604.0f });
    car14.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car14);

    sf::RectangleShape car15(sf::Vector2f(128.0f, 64.0f));
    car15.setPosition({ 855.0f,495.0f });
    car15.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car15);

    sf::RectangleShape car16(sf::Vector2f(128.0f, 64.0f));
    car16.setPosition({ 855.0f,386.0f });
    car16.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car16);

    sf::RectangleShape car17(sf::Vector2f(128.0f, 64.0f));
    car17.setPosition({ 855.0f,277.0f });
    car17.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car17);

    sf::RectangleShape car18(sf::Vector2f(128.0f, 64.0f));
    car18.setPosition({ 855.0f,168.0f });
    car18.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car18);

}

bool ParkedCars::checkCollisions(const Collider& other) const {
    for (const auto& car : m_cars) {
        if (car.checkCollision(other)) {
            return true;
        }
    }
    return false;
}

void ParkedCars::draw(sf::RenderWindow& window) {
    for (const auto& carCollider : m_cars) {
        window.draw(carCollider.getShape());
    }
}