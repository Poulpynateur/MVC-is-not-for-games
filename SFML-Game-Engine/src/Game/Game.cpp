#include "Game.h"

Game::Game(sf::String _name, unsigned int resolutionX, unsigned int resolutionY)
	: name(_name), resolution(resolutionX, resolutionY), world(new World())
{}

Game::~Game() {
	delete world;
}

/**** METHODS ****/

World* Game::buildWorld() {
	//Add object to the game world
	Dynamic* dynamic = new Dynamic(new sf::CircleShape(50), sf::Vector2f(10, 100));
	dynamic->setMovement(sf::Vector2f(0,0.1));
	world->addEntity(dynamic);

	return world;
}