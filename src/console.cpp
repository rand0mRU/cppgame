#include <SFML/Graphics.hpp>
#include <iostream>
#include "console.h"

using namespace std;

class console {

    public:
        bool lastF2 = false;
        bool showConsole = false;
        string out;
        sf::RenderWindow consoleWindow;
            // sf::RenderWindow consoleWindow(sf::VideoMode(), "Console", sf::Style::Titlebar);
        
        void init() {
            sf::RenderWindow consoleWindow(sf::VideoMode(), "Console", sf::Style::Titlebar);
            // consoleWindow.close();
            consoleWindow.setVisible(false);
        }
        void frame(sf::RenderWindow &window) {
            bool focus = window.hasFocus();

            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2) && focus) lastF2 = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2) && !lastF2 && focus) {
                showConsole = !showConsole;
                lastF2 = true;
                if (showConsole) {
                    show();
                } else {
                    hide();
                }
            }



        }
        void show() {
            consoleWindow.setVisible(true);
        }
        void hide() {
            consoleWindow.setVisible(false);
        }
};

// namespace console2
// {
//     bool lastF2 = false;
//     bool showConsole = false;
//     string console;
//     sf::RenderWindow consoleWindow(sf::VideoMode({600,600}), "Console", sf::Style::Titlebar);
//     // sf::RenderWindow window(sf::VideoMode({600,600}), "Console", sf::Style::None);
//     void init() {
//         // consoleWindow.close();
//         consoleWindow.setVisible(false);
//     }
//     void frame(sf::RenderWindow &window) {
//         bool focus = window.hasFocus();

//         if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2) && focus) lastF2 = false;
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2) && !lastF2 && focus) {
//             showConsole = !showConsole;
//             lastF2 = true;
//             if (showConsole) {
//                 show();
//             } else {
//                 hide();
//             }
//         }



//     }
//     void show() {
//         consoleWindow.setVisible(true);
//     }
//     void hide() {
//         consoleWindow.setVisible(false);
//     }
// };