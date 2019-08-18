#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "Object/Object.h"
#include "Object/Dynamic.h"

/**
* World is specific to each games
*/
#include "../Game/Player.h"
#include "../Game/Bullet.h"

#define OBJECT_NBR 50

class World {
private:

	sf::Int32 clock;
	sf::Vector2u bounds;

	std::vector<Object*> statics;
	std::vector<Dynamic*> dynamics;

public:

	World(sf::Vector2u _bounds)
	: bounds(_bounds), clock(0)
	{
		dynamics.push_back(new Player(new PhysicComponent(), new PlayerInputs()));
	}
	~World() {
		for (unsigned int i=0; i < statics.size(); i++) {
			delete statics[i];
		}
		for (unsigned int i = 0; i < dynamics.size(); i++) {
			delete dynamics[i];
		}
	}

	sf::Int32& getClock() {
		return clock;
	}
	void setClock(sf::Int32 _clock) {
		clock = _clock;
	}

	std::vector<Object*>& getStatics() {
		return statics;
	}
	std::vector<Dynamic*>& getDynamics() {
		return dynamics;
	}

	sf::Vector2u& getBounds() {
		return bounds;
	}

	void deleteDynamic(unsigned int index) {
		delete dynamics[index];
		dynamics.erase(dynamics.begin() + index);
	}
	void deleteStatic(unsigned int index) {
		delete statics[index];
		statics.erase(statics.begin() + index);
	}

	void addDynamic(Dynamic* _dynamic) {
		dynamics.push_back(_dynamic);
	}
	void addStatic(Dynamic* _static) {
		statics.push_back(_static);
	}

	//Will be supresed then the Engine will be completly separated from the Game
	void shootBullet(sf::Vector2f velocity, sf::Vector2f pos) {
		dynamics.push_back(new Bullet(sf::Vector2f(), pos, new PhysicComponent()));
	}
};
