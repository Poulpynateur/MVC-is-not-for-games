#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape {
protected:
    bool collision = false;
    sf::Int32 action_timer;

    virtual void onCollision();
    virtual void afterCollision();
public:
    Object(float radius);
    /**
     * Refresh object aspect
     * Call it after logic
     * */
    Object& refresh();

    bool checkCollision(Object& object);
    void setCollision(bool _collision);
};

Object::Object(float radius) : sf::CircleShape(radius) {
    this->setOrigin(getPosition().x + getRadius(), getPosition().y + getRadius());
}

Object& Object::refresh() {
    if(collision)
        onCollision();
    else
        afterCollision();

    this->collision = false;
    return *this;
}

/*Collision*/
bool Object::checkCollision(Object& object) {
    float distance = utility::pointsDistance(this->getPosition(), object.getPosition());
    float radius = utility::sq<float>(object.getRadius() + this->getRadius());

    bool _collision = (distance <= radius)? true : false;

    setCollision(_collision);
    object.setCollision(_collision);
    return collision;
}

void Object::setCollision(bool _collision) {
    if(_collision != false && this->collision != true)
        this->collision = _collision;
}

void Object::onCollision() {
    this->setFillColor(sf::Color::Red);
}
void Object::afterCollision() {
    this->setFillColor(sf::Color::White);
}