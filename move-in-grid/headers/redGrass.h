#ifndef PORUSZANIEPORENDERZE_ALGITP_REDGRASS_H
#define PORUSZANIEPORENDERZE_ALGITP_REDGRASS_H


#include <SFML/Graphics.hpp>

using namespace sf;

class redGrass {
private:
    RectangleShape redGrassShape;

public:
    redGrass(Vector2f position, Vector2f size);

    RectangleShape getShape();
};


#endif
