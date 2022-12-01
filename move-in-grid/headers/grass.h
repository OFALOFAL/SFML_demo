#ifndef PORUSZANIEPORENDERZE_ALGITP_GRASS_H
#define PORUSZANIEPORENDERZE_ALGITP_GRASS_H


#include <SFML/Graphics.hpp>

using namespace sf;

class grass {
private:
    RectangleShape grassShape;

public:
    grass(Vector2f position, Vector2f size);

    RectangleShape getShape();
};


#endif
