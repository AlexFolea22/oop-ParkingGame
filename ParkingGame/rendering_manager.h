#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include <SFML/Graphics.hpp>
#include "game_manager.h" 

class RenderingManager {
public:
    RenderingManager();
    void render(sf::RenderWindow& window, GameManager& gameManager);

};

#endif // RENDERINGMANAGER_H