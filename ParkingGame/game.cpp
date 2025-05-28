#include "game.h"
#include <optional> 


Game::Game(unsigned int width, unsigned int height, const std::string& windowName) :
    m_window(sf::VideoMode({ width, height }), windowName),
    m_gameManager(width, height)                          
{
    m_window.setFramerateLimit(60);
}


void Game::run() {

    m_deltaClock.restart();

    while (m_window.isOpen()) {

        sf::Time frameTime = m_deltaClock.restart();
        float dt = frameTime.asSeconds();

        processEvents();

        if (m_gameManager.shouldClose()) {
            m_window.close();
        }

        if (!m_window.isOpen()) {
            break;
        }

        updateGame(dt);
        renderGame();
    }
}

void Game::processEvents() {
    while (const std::optional event = m_window.pollEvent()) {
        if (!m_gameManager.handleEvent(*event)) {
            m_window.close();
            break;            
        }
    }
}

void Game::updateGame(float dt) {
    m_gameManager.update(dt);
}

void Game::renderGame() {
    m_renderingManager.render(m_window, m_gameManager);
}