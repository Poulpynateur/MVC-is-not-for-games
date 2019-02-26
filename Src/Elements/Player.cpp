class Player : public Dynamic {
private:
    //In pixel per milliseconds
    float speed = 0.5;
public:
    Player(float radius);
    sf::Vector2f nextMovement(sf::Int32 movement_factor);
};

Player::Player(float radius=10) : Dynamic(radius) {
}

sf::Vector2f Player::nextMovement(sf::Int32 movement_factor) {
    sf::Vector2f next;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        next.x = -speed*movement_factor;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        next.x = speed*movement_factor;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        next.y = -speed*movement_factor;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        next.y = speed*movement_factor;

    return next;
}
