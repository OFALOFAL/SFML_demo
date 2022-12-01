#include "player.h"

player::player(Vector2f startPosition) {
    p.setSize(Vector2f(20,20));
    p.setFillColor(Color::Black);
    p.setPosition(startPosition);
    position=startPosition;
}

Vector2f player::getPosition() {
    return position;
}

void player::setPosition(Vector2f newPosition) {
    position = newPosition;
}

RectangleShape player::getShape() {
    return p;
}

void player::update() {
    p.setPosition(position);
}