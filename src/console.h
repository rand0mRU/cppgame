#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef CONSOLE_H
#define CONSOLE_H

class console
{
    public:
        sf::RenderWindow consoleWindow;
        void frame(sf::RenderWindow &window);
        void hide();
        void show();
        void init();
};

#endif // CONSOLE_H