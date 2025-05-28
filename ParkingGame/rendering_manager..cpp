#include "rendering_manager.h"
RenderingManager::RenderingManager() {
	std::cout << "s-a randat";
}

void RenderingManager::render(sf::RenderWindow& window, GameManager& gameManager) {
	window.clear();
	gameManager.getFloor().draw(window);
	window.draw(gameManager.getCar().getRectangle());
	/*window.draw(gameManager.getCubShape()); */
	gameManager.getMapBoundary().draw(window);
	gameManager.getParkedCars().draw(window);
	gameManager.getParkingSpot().draw(window);

	for (const Human* human_ptr : gameManager.getHumans()) {
		if (human_ptr) {
			human_ptr->draw(window);
		}
	}

	window.display();
}