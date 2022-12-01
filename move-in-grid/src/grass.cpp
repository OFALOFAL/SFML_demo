#include "grass.h"

grass::grass(Vector2f position, Vector2f size) {
    grassShape.setSize(size);
    grassShape.setFillColor(Color::Green);
    grassShape.setPosition(position);
}

RectangleShape grass::getShape() {
    return grassShape;
}