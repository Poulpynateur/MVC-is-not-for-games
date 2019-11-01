#include "Game.h"

#include "Objects/Player.h"

Game::Game(sf::String _name, unsigned int resolutionX, unsigned int resolutionY)
	: name(_name), resolution(resolutionX, resolutionY), world(new World())
{}

Game::~Game() {
	delete world;
}

/**** METHODS ****/

World* Game::buildWorld() {
	//Add object to the game world

	world->addEntity(Layer::OBJECTS, new Player(new PlayerInputs(), new PlayerPhysics(), new PlayerGraphics()));

	return world;
}