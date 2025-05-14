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


    sf::RectangleShape car19(sf::Vector2f(128.0f, 64.0f));
    car19.setPosition({ 1140.0f,711.0f });
    car19.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car19);

    sf::RectangleShape car20(sf::Vector2f(128.0f, 64.0f));
    car20.setPosition({ 1140.0f,604.0f });
    car20.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car20);

    sf::RectangleShape car21(sf::Vector2f(128.0f, 64.0f));
    car21.setPosition({ 1140.0f,495.0f });
    car21.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car21);

    sf::RectangleShape car22(sf::Vector2f(128.0f, 64.0f));
    car22.setPosition({ 1140.0f,386.0f });
    car22.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car22);

    sf::RectangleShape car23(sf::Vector2f(128.0f, 64.0f));
    car23.setPosition({ 1140.0f,277.0f });
    car23.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car23);

    sf::RectangleShape car24(sf::Vector2f(128.0f, 64.0f));
    car24.setPosition({ 1140.0f,168.0f });
    car24.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car24);


    sf::RectangleShape car25(sf::Vector2f(128.0f, 64.0f));
    car25.setPosition({ 1140.0f,386.0f });
    car25.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car25);

    sf::RectangleShape car26(sf::Vector2f(128.0f, 64.0f));
    car26.setPosition({ 1140.0f,277.0f });
    car26.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car26);

    sf::RectangleShape car27(sf::Vector2f(128.0f, 64.0f));
    car27.setPosition({ 1140.0f,168.0f });
    car27.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car27);

    sf::RectangleShape car28(sf::Vector2f(64.0f, 128.0f));
    car28.setPosition({ 1408.0f,58.0f });
    car28.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car28);

    sf::RectangleShape car29(sf::Vector2f(64.0f, 128.0f));
    car29.setPosition({ 1516.0f,58.0f });
    car29.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car29);

    sf::RectangleShape car30(sf::Vector2f(64.0f, 128.0f));
    car30.setPosition({ 1624.0f,58.0f });
    car30.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car30);

    sf::RectangleShape car31(sf::Vector2f(64.0f, 128.0f));
    car31.setPosition({ 1300.0f,58.0f });
    car31.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car31);


    sf::RectangleShape car32(sf::Vector2f(64.0f, 128.0f));
    car32.setPosition({ 1518.0f,428.0f });
    car32.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car32);

    sf::RectangleShape car33(sf::Vector2f(64.0f, 128.0f));
    car33.setPosition({ 1518.0f,584.0f });
    car33.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car33);

    sf::RectangleShape car34(sf::Vector2f(64.0f, 128.0f));
    car34.setPosition({ 1518.0f,740.0f });
    car34.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car34);

    sf::RectangleShape car35(sf::Vector2f(64.0f, 128.0f));
    car35.setPosition({ 1795.0f,740.0f });
    car35.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car35);

    sf::RectangleShape car36(sf::Vector2f(64.0f, 128.0f));
    car36.setPosition({ 1795.0f,428.0f });
    car36.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car36);

    sf::RectangleShape car37(sf::Vector2f(64.0f, 128.0f));
    car37.setPosition({ 1795.0f,272.0f });
    car37.setFillColor(sf::Color::Red);
    m_cars.emplace_back(car37);



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