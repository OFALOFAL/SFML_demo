#include "Engine.h"
#include "player.h"

void Engine::update() {
    if (timeSinceLastMove.asSeconds() >= seconds(0.8).asSeconds()) {
        if (!directionQueue.empty()) {
            switch (playerDirection) {
                case Direction::UP:
                    if (directionQueue.front() != Direction::DOWN) {
                        playerDirection = directionQueue.front();
                    }
                    break;
                case Direction::DOWN:
                    if (directionQueue.front() != Direction::UP) {
                        playerDirection = directionQueue.front();
                    }
                    break;
                case Direction::LEFT:
                    if (directionQueue.front() != Direction::RIGHT) {
                        playerDirection = directionQueue.front();
                    }
                    break;
                case Direction::RIGHT:
                    if (directionQueue.front() != Direction::LEFT) {
                        playerDirection = directionQueue.front();
                    }
                    break;
            }
            directionQueue.pop_front();
        }

        // Update the snake's head position
        switch (playerDirection) {
            case Direction::RIGHT:
                player[0].setPosition(Vector2f(player[0].getPosition().x + 20, player[0].getPosition().y));
                break;
            case Direction::DOWN:
                player[0].setPosition(Vector2f(player[0].getPosition().x, player[0].getPosition().y + 20));
                break;
            case Direction::LEFT:
                player[0].setPosition(Vector2f(player[0].getPosition().x - 20, player[0].getPosition().y));
                break;
            case Direction::UP:
                player[0].setPosition(Vector2f(player[0].getPosition().x, player[0].getPosition().y - 20));
                break;
        }

        for (auto &p:player) {
            if (p.getPosition().x<0){
                p.setPosition(Vector2f(140,p.getPosition().y));
                if (currentTile==1){
                    currentTile=2;
                    loadTile2();
                }
                else{
                    currentTile=1;
                    loadTile1();
                }

            }

            if (p.getPosition().x>140){
                p.setPosition(Vector2f(0,p.getPosition().y));
                if (currentTile==1){
                    currentTile=2;
                    loadTile2();
                }
                else{
                    currentTile=1;
                    loadTile1();
                }

            }

            if (p.getPosition().y<0){
                p.setPosition(Vector2f(p.getPosition().x,140));
                if (currentTile==1){
                    currentTile=2;
                    loadTile2();
                }
                else{
                    currentTile=1;
                    loadTile1();
                }

            }

            if (p.getPosition().y>140){
                p.setPosition(Vector2f(p.getPosition().x,0));
                if (currentTile==1){
                    currentTile=2;
                    loadTile2();
                }
                else{
                    currentTile=1;
                    loadTile1();
                }

            }

        }

        for (auto &p: player) {
            p.update();
        }

        timeSinceLastMove = Time::Zero;
    }
}