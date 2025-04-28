#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef UI_H
#define UI_H

namespace ui
{
    void init(sf::RenderWindow &window);
    void showFPS(sf::RenderWindow &window, float fps);
    bool getButton(sf::RenderWindow &window, sf::Sprite &sprite);
    void uiUpdater(sf::RenderWindow &window);
};

#endif // UI__H