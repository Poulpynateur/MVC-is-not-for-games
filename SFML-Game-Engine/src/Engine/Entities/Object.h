#pragma once

#include "Entity.h"
#include <iostream>

template <typename Parent, typename ComponentInputs, typename ComponentPhysics, typename ComponentGraphics>
struct Object : public Entity {

	ComponentInputs* inputs;
	ComponentPhysics* physics;
	ComponentGraphics* graphics;

	Object(ComponentInputs* _inputs, ComponentPhysics* _physics, ComponentGraphics* _graphics)
		: inputs(_inputs), physics(_physics), graphics(_graphics)
	{}
	~Object() {
		delete inputs;
		delete physics;
		delete graphics;
	}

	void draw(sf::RenderWindow& render, float interpolation) {
		render.draw(graphics->refresh(interpolation));
	};

	void update(World* world) {
		inputs->update(static_cast<Parent*>(this), world);
		physics->update(static_cast<Parent*>(this), world);
		graphics->update(static_cast<Parent*>(this));
	};
};