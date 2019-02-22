#pragma once
#include "Elements/Elements.cpp"

class Interaction {
protected:
    Elements& elements;
public:
    Interaction(Elements& _elements);
};

Interaction::Interaction(Elements& _elements) :
elements(_elements)
{}