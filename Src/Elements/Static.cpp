class Static : public sf::CircleShape {
private:
    /* data */
public:
    Static(float radius);
    /**
     * TODO
     * inerithed member is not allowed
     * In children class Player
     */
    //void update();
};

Static::Static(float radius=50) : sf::CircleShape(radius)
{}