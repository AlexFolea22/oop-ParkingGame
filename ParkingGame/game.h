#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "game_manager.h"
#include "rendering_manager.h"
#include <string> 

class Game {
private:
    sf::RenderWindow m_window;
    GameManager m_gameManager;
    RenderingManager m_renderingManager;
    sf::Clock m_deltaClock;

    void processEvents();
    void updateGame(float dt);
    void renderGame();

public:
    Game(unsigned int width, unsigned int height, const std::string& windowName);
    void run();
};

#endif //GAME_H