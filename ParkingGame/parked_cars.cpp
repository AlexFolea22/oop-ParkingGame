#include "parked_cars.h"
ParkedCars::ParkedCars() {

    sf::RectangleShape car1(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture1 = new sf::Texture();
    if (texture1->loadFromFile("Sprites/BlueCar.png")) {
        car1.setTexture(texture1);
    }
    car1.setPosition({ 65.0f,711.0f });
    /*car1.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car1);

    sf::RectangleShape car2(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture2 = new sf::Texture();
    if (texture2->loadFromFile("Sprites/Car3.png")) {
        car2.setTexture(texture2);
    }
    car2.setPosition({ 65.0f,604.0f });
    /*car2.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car2);

    sf::RectangleShape car3(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture3 = new sf::Texture();
    if (texture3->loadFromFile("Sprites/Car4.png")) {
        car3.setTexture(texture3);
    }
    car3.setPosition({ 65.0f,495.0f });
    /*car3.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car3);

    sf::RectangleShape car4(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture4 = new sf::Texture();
    if (texture4->loadFromFile("Sprites/Car3.png")) {
        car4.setTexture(texture4);
    }
    car4.setPosition({ 65.0f,386.0f });
    /*car4.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car4);

    sf::RectangleShape car5(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture5 = new sf::Texture();
    if (texture5->loadFromFile("Sprites/Car3.png")) {
        car5.setTexture(texture5);
    }
    car5.setPosition({ 65.0f,277.0f });
    /*car5.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car5);

    sf::RectangleShape car6(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture6 = new sf::Texture();
    if (texture6->loadFromFile("Sprites/Car3.png")) {
        car6.setTexture(texture6);
    }
    car6.setPosition({ 65.0f,168.0f });
    /*car6.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car6);

    sf::RectangleShape car7(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture7 = new sf::Texture();
    if (texture7->loadFromFile("Sprites/Car3.png")) {
        car7.setTexture(texture7);
    }
    car7.setPosition({ 520.0f,711.0f });
    /*car7.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car7);

    sf::RectangleShape car8(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture8 = new sf::Texture();
    if (texture8->loadFromFile("Sprites/Car3.png")) {
        car8.setTexture(texture8);
    }
    car8.setPosition({ 520.0f,604.0f });
    /*car8.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car8);

    sf::RectangleShape car9(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture9 = new sf::Texture();
    if (texture9->loadFromFile("Sprites/Car3.png")) {
        car9.setTexture(texture9);
    }
    car9.setPosition({ 520.0f,495.0f });
    /*car9.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car9);

    sf::RectangleShape car10(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture10 = new sf::Texture();
    if (texture10->loadFromFile("Sprites/Car3.png")) {
        car10.setTexture(texture10);
    }
    car10.setPosition({ 520.0f,386.0f });
    /*car10.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car10);

    sf::RectangleShape car11(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture11 = new sf::Texture();
    if (texture11->loadFromFile("Sprites/Car3.png")) {
        car11.setTexture(texture11);
    }
    car11.setPosition({ 520.0f,277.0f });
    /*car11.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car11);

    sf::RectangleShape car12(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture12 = new sf::Texture();
    if (texture12->loadFromFile("Sprites/Car3.png")) {
        car12.setTexture(texture12);
    }
    car12.setPosition({ 520.0f,818.0f });
    /*car12.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car12);

    sf::RectangleShape car13(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture13 = new sf::Texture();
    if (texture13->loadFromFile("Sprites/Car3.png")) {
        car13.setTexture(texture13);
    }
    car13.setPosition({ 855.0f,711.0f });
    /*car13.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car13);

    sf::RectangleShape car14(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture14 = new sf::Texture();
    if (texture14->loadFromFile("Sprites/Car3.png")) {
        car14.setTexture(texture14);
    }
    car14.setPosition({ 855.0f,604.0f });
    /*car14.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car14);

    sf::RectangleShape car15(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture15 = new sf::Texture();
    if (texture15->loadFromFile("Sprites/Car3.png")) {
        car15.setTexture(texture15);
    }
    car15.setPosition({ 855.0f,495.0f });
    /*car15.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car15);

    sf::RectangleShape car16(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture16 = new sf::Texture();
    if (texture16->loadFromFile("Sprites/Car3.png")) {
        car16.setTexture(texture16);
    }
    car16.setPosition({ 855.0f,386.0f });
    /*car16.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car16);

    sf::RectangleShape car17(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture17 = new sf::Texture();
    if (texture17->loadFromFile("Sprites/Car3.png")) {
        car17.setTexture(texture17);
    }
    car17.setPosition({ 855.0f,277.0f });
    /*car17.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car17);

    sf::RectangleShape car18(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture18 = new sf::Texture();
    if (texture18->loadFromFile("Sprites/Car3.png")) {
        car18.setTexture(texture18);
    }
    car18.setPosition({ 855.0f,168.0f });
    /*car18.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car18);

    sf::RectangleShape car19(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture19 = new sf::Texture();
    if (texture19->loadFromFile("Sprites/Car3.png")) {
        car19.setTexture(texture19);
    }
    car19.setPosition({ 1140.0f,711.0f });
    /*car19.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car19);

    sf::RectangleShape car20(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture20 = new sf::Texture();
    if (texture20->loadFromFile("Sprites/Car3.png")) {
        car20.setTexture(texture20);
    }
    car20.setPosition({ 1140.0f,604.0f });
    /*car20.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car20);

    sf::RectangleShape car21(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture21 = new sf::Texture();
    if (texture21->loadFromFile("Sprites/Car3.png")) {
        car21.setTexture(texture21);
    }
    car21.setPosition({ 1140.0f,495.0f });
    /*car21.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car21);

    sf::RectangleShape car22(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture22 = new sf::Texture();
    if (texture22->loadFromFile("Sprites/Car3.png")) {
        car22.setTexture(texture22);
    }
    car22.setPosition({ 1140.0f,386.0f });
    /*car22.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car22);

    sf::RectangleShape car23(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture23 = new sf::Texture();
    if (texture23->loadFromFile("Sprites/Car3.png")) {
        car23.setTexture(texture23);
    }
    car23.setPosition({ 1140.0f,277.0f });
    /*car23.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car23);

    sf::RectangleShape car24(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture24 = new sf::Texture();
    if (texture24->loadFromFile("Sprites/Car3.png")) {
        car24.setTexture(texture24);
    }
    car24.setPosition({ 1140.0f,168.0f });
    /*car24.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car24);

    sf::RectangleShape car25(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture25 = new sf::Texture();
    if (texture25->loadFromFile("Sprites/Car3.png")) {
        car25.setTexture(texture25);
    }
    car25.setPosition({ 1140.0f,386.0f });
    /*car25.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car25);

    sf::RectangleShape car26(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture26 = new sf::Texture();
    if (texture26->loadFromFile("Sprites/Car3.png")) {
        car26.setTexture(texture26);
    }
    car26.setPosition({ 1140.0f,277.0f });
    /*car26.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car26);

    sf::RectangleShape car27(sf::Vector2f(128.0f, 64.0f));
    sf::Texture* texture27 = new sf::Texture();
    if (texture27->loadFromFile("Sprites/Car3.png")) {
        car27.setTexture(texture27);
    }
    car27.setPosition({ 1140.0f,168.0f });
    /*car27.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car27);

    sf::RectangleShape car28(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture28 = new sf::Texture();
    if (texture28->loadFromFile("Sprites/Car2.png")) {
        car28.setTexture(texture28);
    }
    car28.setPosition({ 1408.0f,58.0f });
    /*car28.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car28);

    sf::RectangleShape car29(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture29 = new sf::Texture();
    if (texture29->loadFromFile("Sprites/Car2.png")) {
        car29.setTexture(texture29);
    }
    car29.setPosition({ 1516.0f,58.0f });
    /*car29.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car29);

    sf::RectangleShape car30(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture30 = new sf::Texture();
    if (texture30->loadFromFile("Sprites/Car2.png")) {
        car30.setTexture(texture30);
    }
    car30.setPosition({ 1624.0f,58.0f });
    /*car30.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car30);

    sf::RectangleShape car31(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture31 = new sf::Texture();
    if (texture31->loadFromFile("Sprites/Car2.png")) {
        car31.setTexture(texture31);
    }
    car31.setPosition({ 1300.0f,58.0f });
    /*car31.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car31);

    sf::RectangleShape car32(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture32 = new sf::Texture();
    if (texture32->loadFromFile("Sprites/Car2.png")) {
        car32.setTexture(texture32);
    }
    car32.setPosition({ 1518.0f,428.0f });
    /*car32.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car32);

    sf::RectangleShape car33(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture33 = new sf::Texture();
    if (texture33->loadFromFile("Sprites/Car2.png")) {
        car33.setTexture(texture33);
    }
    car33.setPosition({ 1518.0f,584.0f });
    /*car33.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car33);

    sf::RectangleShape car34(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture34 = new sf::Texture();
    if (texture34->loadFromFile("Sprites/Car2.png")) {
        car34.setTexture(texture34);
    }
    car34.setPosition({ 1518.0f,740.0f });
    /*car34.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car34);

    sf::RectangleShape car35(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture35 = new sf::Texture();
    if (texture35->loadFromFile("Sprites/Car2.png")) {
        car35.setTexture(texture35);
    }
    car35.setPosition({ 1795.0f,740.0f });
    /*car35.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car35);

    sf::RectangleShape car36(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture36 = new sf::Texture();
    if (texture36->loadFromFile("Sprites/Car2.png")) {
        car36.setTexture(texture36);
    }
    car36.setPosition({ 1795.0f,428.0f });
    /*car36.setFillColor(sf::Color::Red);*/
    m_cars.emplace_back(car36);

    sf::RectangleShape car37(sf::Vector2f(64.0f, 128.0f));
    sf::Texture* texture37 = new sf::Texture();
    if (texture37->loadFromFile("Sprites/Car2.png")) {
        car37.setTexture(texture37);
    }
    car37.setPosition({ 1795.0f,272.0f });
    /*car37.setFillColor(sf::Color::Red);*/
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

void ParkedCars::draw(sf::RenderWindow& window)const {
    for (const auto& carCollider : m_cars) {
        window.draw(carCollider.getShape());
    }
}