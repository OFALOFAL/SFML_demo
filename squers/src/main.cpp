#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>


int screenWidth;

int main() {
    sf::RenderWindow window;

    int temp;
    std::cout<<"Type width/height of the window";
    std::cin>>screenWidth;
    std::cout<<"Type density of squares";
    std::cin >>temp;
    int dens = screenWidth / temp;

    std::vector<sf::RectangleShape> v_rect;

    for (int i = 0; i < dens; ++i) {
        for (int j = 0; j < dens; ++j) {
            int X = (i * dens) * dens;
            int Y = (j * dens) * dens;

            sf::RectangleShape rect(sf::Vector2f(dens * dens, dens * dens));
            rect.setPosition(sf::Vector2f(X, Y));
            rect.setFillColor(sf::Color(i * 10 % 255, j * 10 % 255, i * j % 255));
            v_rect.push_back(rect);
        }
    }

    window.create(sf::VideoMode(screenWidth,screenWidth),"squares <3",sf::Style::Default|sf::Style::Resize|sf::Style::Close);
    sf::Event event;
    while (window.isOpen()){
        window.clear(sf::Color::White);
        for (auto rect:v_rect) {
            window.draw(rect);
        }
        window.display();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}

