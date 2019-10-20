#include "Group.h"

#include "../World.h"

/**** GETTERS and SETTERS ****/
std::vector<Entity*>& Group::getChildrens() {
	return childrens;
}

/**** METHDOS ****/
void Group::refresh(sf::RenderWindow& render, float interpolation) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		childrens[i]->refresh(render, interpolation);
	}
}
void Group::update(World* world) {
	for (unsigned int i = 0; i < childrens.size(); i++) {
		childrens[i]->update(world);

		if (childrens[i]->isDismised())
			delete childrens[i];
	}
}