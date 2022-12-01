#include "Engine.h"
#include "player.h"

void Engine::draw() {
    window.clear(Color::White);
    if (currentTile==1){
        for (auto & g : grassSections) {
            window.draw(g.getShape());
        }
    } else{
        for (auto & g : redGrassSections) {
            window.draw(g.getShape());
        }
    }


    for (auto p:player) {
        window.draw(p.getShape());
    }


    window.display();
}
