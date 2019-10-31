#pragma once

#include "Entity.h"
#include "Components/Component.h"
#include "Components/GraphicsComponent.h"

class Object : public Entity {
public:
	Component* inputs;
	Component* physic;
	GraphicsComponent* graphics;

	Object(Component* _inputs, Component* _physic, GraphicsComponent* _graphics);
	~Object();

	virtual void refresh(sf::RenderWindow& render, float interpolation);
	virtual void update(World* world);
};

