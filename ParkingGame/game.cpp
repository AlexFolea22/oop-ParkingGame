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

        _processEvents();

        if (m_gameManager.shouldClose()) {
            m_window.close();
        }

        if (!m_window.isOpen()) {
            break;
        }

        _updateGame(dt);
        _renderGame();
    }
}

void Game::_processEvents() {
    while (const std::optional event = m_window.pollEvent()) {
        if (!m_gameManager.handleEvent(*event)) {
            m_window.close();
            break;            
        }
    }
}

void Game::_updateGame(float dt) {
    m_gameManager.update(dt);
}

void Game::_renderGame() {
    m_renderingManager.render(m_window, m_gameManager);
}