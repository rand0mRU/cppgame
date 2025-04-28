#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef WRLD_H
#define WRLD_H

namespace world
{
    void generateWorld(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void moveTop(float distance);
    void moveLeft(float distance, sf::Sprite &player);
    void moveRight(float distance);
    void moveDown(float distance);
    // bool isMovePlayer(sf::Sprite &player, string direct);
};

#endif