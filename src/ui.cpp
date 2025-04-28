#include <SFML/Graphics.hpp>
#include <iostream>
#include "ui.h"

using namespace std;




namespace ui
{
    // float fps;
    sf::Texture texture1("resources/textures/player.png", false, sf::IntRect({0, 0}, {1184, 1184}));
    sf::Sprite uiObj(texture1);

    sf::Texture rectangle1("resources/textures/white.png", false, sf::IntRect({0, 0}, {10, 10}));
    sf::Texture rectangle2("resources/textures/white.png", false, sf::IntRect({0, 0}, {10, 10}));
    sf::Texture rectangle3("resources/textures/white.png", false, sf::IntRect({0, 0}, {10, 10}));
    sf::Sprite rectangle1sprite(rectangle1);
    sf::Sprite rectangle2sprite(rectangle2);
    sf::Sprite rectangle3sprite(rectangle3);

    sf::Font font("resources/fonts/jost-light.ttf");
    sf::Text fpsText(font);

    

    void init(sf::RenderWindow &window)
    {
        sf::Vector2u winsize = window.getSize();
        cout << winsize.x;
        fpsText.setPosition({0,(float) winsize.y-40});
        rectangle1sprite.setColor(sf::Color::Red);
        rectangle2sprite.setColor(sf::Color::Green);
        rectangle3sprite.setColor(sf::Color::Blue);
        rectangle1sprite.setPosition({0, 0});
        rectangle2sprite.setPosition({0, 10});
        rectangle3sprite.setPosition({10, 0});
        // exitBtn.setColor(sf::Color(255,0,0));
    }

    void showFPS(sf::RenderWindow &window, float fps) {
        fpsText.setString("FPS: "+to_string((int) fps));
        window.draw(fpsText);
    }
    
    bool getButton(sf::RenderWindow &window, sf::Sprite &sprite)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (sprite.getGlobalBounds().contains(mousePosF)) return true;
        } 
        return false;
    }

    void uiUpdater(sf::RenderWindow &window)
    {
        if (getButton(window, uiObj)) {}
        // if (getButton(window, exitBtn)) 
            // window.close();
        
        // window.draw(exitBtn);
        // window.draw(uiObj);
        window.draw(rectangle1sprite);
        window.draw(rectangle2sprite);
        window.draw(rectangle3sprite);
        window.display();
    }
};