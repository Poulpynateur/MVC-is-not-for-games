class Player : public Dynamic {
private:
    //In pixel per milliseconds
    float speed = 0.5;
public:
    Player(float radius);
    void update(sf::Int32 movement_factor);
};

Player::Player(float radius=10) : Dynamic(radius) {
}

void Player::update(sf::Int32 movement_factor) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->move(-speed*movement_factor, 0);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->move(speed*movement_factor, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->move(0, -speed*movement_factor);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->move(0, speed*movement_factor);
}
