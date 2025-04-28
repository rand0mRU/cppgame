#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/ui.h"
#include "src/world.h"
#include "src/console.h"
#include <thread>

using namespace std;

int main()
{
    bool showFPS = false;
    bool lastF1 = false;
    // create the window
    // sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Pixel | Faistorm", sf::State::Fullscreen);
    sf::RenderWindow window(sf::VideoMode({1366,768}), "Pixel | Faistorm");
    sf::RectangleShape loadbar({100.f, 10.0f});
    loadbar.setPosition({0,1070});
    loadbar.setFillColor(sf::Color::Blue);
    window.draw(loadbar);
    window.display();
    float fps;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    // window.setSize(window.getSize());

    ui::init(window);
    console::init();
    loadbar.setSize({100.0F,20.0F});
    window.draw(loadbar);
    window.display();
    // std::this_thread::sleep_for(chrono::seconds(5));
    world::generateWorld(window);
    loadbar.setSize({100.0F,75.0F});
    window.draw(loadbar);
    window.display();
    // std::this_thread::sleep_for(chrono::seconds(5));


    
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    sf::Texture texture("resources/textures/player.png", false, sf::IntRect({0, 0}, {1184, 1184}));
    // texture.resize({200, 200});
    texture.setSmooth(true);
    sf::Sprite player(texture);
    player.setScale({0.1F, 0.1F});
    player.setPosition({(float)window.getSize().x / 2, (float)window.getSize().y / 2});
    loadbar.setSize({100.0F,100.0F});
    window.draw(loadbar);
    window.display();

    // sf::RectangleShape rectangle1({10.f, 10.f});
    // sf::RectangleShape rectangle2({10.f, 10.f});
    // sf::RectangleShape rectangle3({10.f, 10.f});
    // rectangle1.setFillColor(sf::Color::Red);
    // rectangle2.setFillColor(sf::Color::Green);
    // rectangle3.setFillColor(sf::Color::Blue);
    // rectangle1.setPosition({0, 0});
    // rectangle2.setPosition({0, 10});
    // rectangle3.setPosition({10, 0});

    // run the program as long as the window is open
    while (window.isOpen())
    {

        start = std::chrono::high_resolution_clock::now();
        bool focus = window.hasFocus();
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
                
            // if (event->is<sf::Event::MouseButtonPressed>())
            // {
            //     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //     sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            //     if (sprite.getGlobalBounds().contains(mousePosF)) {
            //         cout << "click";
            //         window.close();
            //     }
            // }
        }

        if (focus) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && focus)
                window.close();

            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1)) lastF1 = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1) && !lastF1) {
                showFPS = !showFPS;
                lastF1 = true;
            }
        }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        //     player.move({0.0F, -2.0F});
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        //     player.move({-2.0F, 0.0F});
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        //     player.move({0.0F, 2.0F});
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        //     player.move({2.0F, 0.0F});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && focus)
            world::moveTop(0.1F);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && focus)
            world::moveRight(0.1F);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && focus)
            world::moveDown(0.1F);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && focus)
            world::moveLeft(0.1F, player);

        window.clear(sf::Color::White);
        world::draw(window);
        window.draw(player);

        // window.draw(rectangle1);
        // window.draw(rectangle2);
        // window.draw(rectangle3);

        ui::uiUpdater(window);
        console::frame(window);

        end = std::chrono::high_resolution_clock::now();
        fps = (float)1e9/(float)std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        if (showFPS) ui::showFPS(window,fps);
        // ui::getButton(window, player);

        window.display();
    }
}