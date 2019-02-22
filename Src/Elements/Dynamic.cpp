class Dynamic : public Static {
private:
    /* data */
public:
    Dynamic(float radius);
};

Dynamic::Dynamic(float radius) : Static(radius) {
}
