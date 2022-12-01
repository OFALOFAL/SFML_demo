#include "redGrass.h"

redGrass::redGrass(Vector2f position, Vector2f size) {
    redGrassShape.setSize(size);
    redGrassShape.setFillColor(Color::Red);
    redGrassShape.setPosition(position);
}

RectangleShape redGrass::getShape() {
    return redGrassShape;
}
