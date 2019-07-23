#include "Object.hpp"

Object::Object(InputsComponent* _inputs)
: inputs(_inputs) 
{}
Object::~Object() {
    delete inputs;
}

void Object::update(std::unordered_map<sf::Keyboard::Key, bool>& keys) {
    inputs->update(*this, keys);
}