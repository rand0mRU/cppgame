#include <SFML/Graphics.hpp>
#include <iostream>
#include "world.h"

using namespace std;

// sf::Texture texture1("player.png", false, sf::IntRect({100, 100}, {1184, 1184}));
// sf::Sprite uiObj(texture1);

namespace world
{
    float layer0[10000][3] = {{0,0,1}};
    float layer1[100][3] = {{0, 0, 2}, {0, 1, 2}, {2, 2, 2}, {2, 99, 2}};
    // float layer1[100][3] = {{0, 0, 2}};
    sf::Texture grass("grass1.png", false, sf::IntRect({0, 0}, {64, 64}));
    sf::Sprite grassSprite(grass);
    sf::Texture tree("tree.png", false, sf::IntRect({0, 0}, {640, 640}));
    sf::Sprite treeSprite(tree);
    // void generateWorld(sf::RenderWindow &window)
    // {
    //     sf::Texture temptexture("grass.png", false, sf::IntRect({0, 0}, {16, 16}));
    //     for (int i = 0; i < 100; i++) {
    //         sf::Sprite tempObj(temptexture);
    //         layer0[i] = tempObj;
    //     }
    // }
    void generateWorld(sf::RenderWindow &window)
    {
        // sf::Texture temptexture("grass.png", false, sf::IntRect({0, 0}, {16, 16}));
        treeSprite.setScale({0.15, 0.15});
        int all = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int a = 0; a < 10; a++)
            {
                layer0[all][0] = (float)i;
                layer0[all][1] = (float)a;
                layer0[all][2] = (float)1;
                all++;
            }
        }
    }
    void draw(sf::RenderWindow &window)
    {
        for (int i = 0; i < size(layer0); i++)
        {
            if (layer0[i][2] == 0)
            {
            }
            else if (layer0[i][2] == 1)
            {
                // grass.resize({64, 64}, false);
                grassSprite.setPosition({(float)layer0[i][0] * 64, (float)layer0[i][1] * 64});
                window.draw(grassSprite);
                // cout << "draw";
            }
            else if (layer0[i][2] == 2)
            {
                // grass.resize({64, 64}, false);
                treeSprite.setPosition({(float)layer0[i][0] * 64, (float)layer0[i][1] * 64});
                window.draw(treeSprite);
                // cout << "draw";
            }
        }
        for (int i = 0; i < size(layer1); i++)
        {
            if (layer1[i][2] == 0)
            {
            }
            else if (layer1[i][2] == 1)
            {
                // grass.resize({64, 64}, false);
                grassSprite.setPosition({(float)layer1[i][0] * 64, (float)layer1[i][1] * 64});
                window.draw(grassSprite);
                // cout << "draw";
            }
            else if (layer1[i][2] == 2)
            {
                // grass.resize({64, 64}, false);
                treeSprite.setPosition({(float)layer1[i][0] * 64 - 16.0F, (float)layer1[i][1] * 64 - 24.0F});
                window.draw(treeSprite);
                // cout << "draw";
            }
        }
    }
    void moveTop(float distance)
    {
        for (int i = 0; i < size(layer0); i++)
            layer0[i][1] += distance;
        for (int i = 0; i < size(layer1); i++)
            layer1[i][1] += distance;
    }
    void moveRight(float distance)
    {
        for (int i = 0; i < size(layer0); i++)
            layer0[i][0] += distance;
        for (int i = 0; i < size(layer1); i++)
            layer1[i][0] += distance;
    }
    void moveLeft(float distance, sf::Sprite &player)
    {
        for (int i = 0; i < size(layer1); i++)
            if (layer1[i][0]*6<player.getPosition().x) {}
            else layer1[i][0] -= distance;
        for (int i = 0; i < size(layer0); i++)
            layer0[i][0] -= distance;
    }
    void moveDown(float distance)
    {
        for (int i = 0; i < size(layer0); i++)
            layer0[i][1] -= distance;
        for (int i = 0; i < size(layer1); i++)
            layer1[i][1] -= distance;
    }
//     bool isMovePlayer(sf::Sprite &player, string direct) {
//         if (direct=="left") {
//             for (int i = 0; i < size(layer1); i++)
//             {
//                 if (layer1[i][0]+64 < player.getPosition().x) return false;
//             }
//         }
//         return false;
//     }
};