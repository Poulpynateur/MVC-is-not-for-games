#include "Group.h"

#include "../World.h"

Group::~Group() {
	for (auto element : childrens) {
		delete element;
	}
	childrens.clear();
}

/**** GETTERS and SETTERS ****/
std::vector<Entity*>& Group::getChildrens() {
	return childrens;
}

/**** METHDOS ****/
void Group::draw(sf::RenderWindow& render, float interpolation) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		childrens[i]->draw(render, interpolation);
	}
}
void Group::update(World* world) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		childrens[i]->update(world);

		if (childrens[i]->isDismised())
			delete childrens[i];
	}
}