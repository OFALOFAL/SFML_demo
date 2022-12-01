//
// Created by olafl on 25.05.2022.
//

#include <iostream>
#include "Engine.h"
#include "player.h"

Engine::Engine() {
    resolution = Vector2f(160,160);
    window.create(VideoMode(resolution.x, resolution.y), "Nibbles", Style::Default | Style::Close);
    player.emplace_back(Vector2f(window.getSize().x/2,window.getSize().y/2));
    playerDirection=Direction::RIGHT;
    currentTile=1;
    loadTile1();
}

void Engine::loadTile1() {
    std::ifstream in_file;
    in_file.open("assets/tiles/tile1.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        window.close();
    }

    char c {};
    int x{},y{};
    while (in_file.get(c)) {
        if (x<8)x++;
        else {x=0; y++;}

        if (c=='x'){
            grassSections.emplace_back(grass(Vector2f(x * 20 -20, y * 20), Vector2f(20, 20)));
        }
    }
    std::cout << std::endl;
    in_file.close();
}

void Engine::loadTile2() {
    std::ifstream in_file;
    in_file.open("assets/tiles/tile2.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        window.close();
    }

    char c {};
    int x{},y{};
    while (in_file.get(c)) {
        if (x<8)x++;
        else {x=0; y++;}

        if (c=='x'){
            redGrassSections.emplace_back(redGrass(Vector2f(x * 20 -20, y * 20), Vector2f(20, 20)));
        }
    }
    std::cout << std::endl;
    in_file.close();
}

sf::Event event;
void Engine::run() {
    Clock clock;
    while (window.isOpen()){
        Time dt = clock.restart();
        timeSinceLastMove += dt;

        input();
        update();
        draw();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}