#include "game.h"
#include <optional> 

Game::Game(unsigned int width, unsigned int height, const std::string& windowName) :
    m_window(sf::VideoMode({ width, height }), windowName),
    m_gameManager(width, height)                          
{
    m_window.setFramerateLimit(60);
}

void Game::run() {
    while (m_window.isOpen()) {
        processEvents();

        if (m_gameManager.shouldClose()) {
            m_window.close();
        }

        if (!m_window.isOpen()) {
            break;
        }

        updateGame();
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

void Game::updateGame() {
    m_gameManager.update();
}

void Game::renderGame() {
    m_renderingManager.render(m_window, m_gameManager);
}