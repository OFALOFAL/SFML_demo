#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>


int screenWidth = 1000;

int main() {
    while (true){
        sf::RenderWindow window;

        int width;
        std::cout << "Type density of squares (type 0 or non-intiger to quit)";
        std::cin >> width;
        if (width == 0)
            break;
        else if (width > 100)
            width = 100;
        else if (width < 50)
            width = 50;

        int dens = screenWidth / width;

        std::vector<sf::RectangleShape> v_rect;

        for (int i = 0; i < dens; ++i) {
            for (int j = 0; j < dens; ++j) {
                int X = (i * dens) * dens;
                int Y = (j * dens) * dens;

                sf::RectangleShape rect(sf::Vector2f(width * dens, width * dens));
                rect.setPosition(sf::Vector2f(X, Y));
                rect.setFillColor(sf::Color(20 + i * width * dens % 255, 20 + j * width * dens % 255, 20 + i * j * width * dens % 255));
                v_rect.push_back(rect);
            }
        }

        window.create(sf::VideoMode(screenWidth, screenWidth), "squares <3",
                      sf::Style::Default | sf::Style::Resize | sf::Style::Close);
        sf::Event event;
        while (window.isOpen()) {
            window.clear(sf::Color::White);
            for (auto rect: v_rect) {
                window.draw(rect);
            }
            window.display();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }
}

