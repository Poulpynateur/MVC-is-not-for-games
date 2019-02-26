class Dynamic : public Static {
private:
    /* data */
public:
    Dynamic(float radius);

    sf::Vector2f nextMovement(sf::Int32 movement_factor);
};

Dynamic::Dynamic(float radius) : Static(radius) {
}
