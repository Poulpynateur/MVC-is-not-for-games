#include "Object.h"

#include "../World.h"

Object::Object(Component* _inputs, Component* _physic, GraphicsComponent* _graphics)
: inputs(_inputs), physic(_physic), graphics(_graphics)
{}

Object::~Object() {
	delete inputs, physic, graphics;
}

/**** METHODS ****/

void Object::refresh(sf::RenderWindow& render, float interpolation) {
	graphics->draw(render, interpolation);
}
void Object::update(World* world) {
	inputs->update(*this, world);
	physic->update(*this, world);
	graphics->update(*this, world);
}