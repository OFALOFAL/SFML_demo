#include "Engine.h"

void Engine::input() {
    if (Keyboard::isKeyPressed(Keyboard::Escape)){
        window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)){
        for (auto p:player) {
            playerDirection=Direction::UP;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)){
        for (auto p:player) {
            playerDirection=Direction::RIGHT;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)){
        for (auto p:player) {
            playerDirection=Direction::DOWN;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)){
        for (auto p:player) {
            playerDirection=Direction::LEFT;
        }
    }

}

void Engine::addDirection(int newDirection) {
    if (directionQueue.empty()) {
        directionQueue.emplace_back(newDirection);
    }
    else {
        if (directionQueue.back() != newDirection) {
            directionQueue.emplace_back(newDirection);
        }
    }
}
