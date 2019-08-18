#pragma once
#include <SFML/Graphics.hpp>

class Object {
protected:

	bool state;

	sf::Vector2f position;
	sf::Shape* shape;

public:
	Object(sf::Shape* _shape);
	~Object();

	sf::Vector2f getPos();
	void setPos(sf::Vector2f _pos);
	void setPos(float x, float y);

	void setState(bool _state);
	bool getState();

	sf::Shape* getShape();

	//Refresh display to render
	virtual sf::Shape* refresh();
};
