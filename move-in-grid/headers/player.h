#ifndef PORUSZANIEPORENDERZE_ALGITP_PLAYER_H
#define PORUSZANIEPORENDERZE_ALGITP_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

using namespace sf;

class player {
private:
    Vector2f position=Vector2f(0,0);
    RectangleShape p;
public:
    explicit player(Vector2f startPosition);
    Vector2f getPosition();
    void setPosition(Vector2f newPosition);

    RectangleShape getShape();

    void update();
};


#endif
