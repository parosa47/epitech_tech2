/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** printIMG.cpp
*/

#include "printIMG.hpp"

void SFML::printIMG(std::vector<Pixel> pixelsList, Camera camera) {
    int width = camera.getResolution().first;
    int height = camera.getResolution().second;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (size_t i = 0; i < pixelsList.size(); i++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(1, 1));
            rectangle.setPosition(pixelsList[i].coord.x, pixelsList[i].coord.y);
            rectangle.setFillColor(sf::Color(pixelsList[i].color.x, pixelsList[i].color.y, pixelsList[i].color.z));
            window.draw(rectangle);
        }
        window.display();
    }
    window.close();
}
