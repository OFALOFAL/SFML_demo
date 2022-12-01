#ifndef PORUSZANIEPORENDERZE_ALGITP_ENGINE_H
#define PORUSZANIEPORENDERZE_ALGITP_ENGINE_H

#include "player.h"
#include "grass.h"
#include "redGrass.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <deque>
#include <fstream>

using namespace sf;

class Engine {
private:
    Vector2f resolution;
    RenderWindow window;
    std::vector<player> player;
    std::vector<grass> grassSections;
    std::vector<redGrass> redGrassSections;
    int currentTile;

    int playerDirection;
    std::deque<int> directionQueue;

    Time timeSinceLastMove;
public:
    enum Direction { UP, RIGHT, DOWN, LEFT };
    Engine();

    void input();
    void addDirection(int newDirection);
    void update();
    void draw();

    void loadTile1();
    void loadTile2();

    void run();
};


#endif
