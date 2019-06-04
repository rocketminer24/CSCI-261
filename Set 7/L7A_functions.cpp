//
// Created by Jarod Spencer1 on 2019-04-14.
//

#include "functions.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void drawSun(RenderWindow &window)  {
    CircleShape sun;
    sun.setRadius(100);
    sun.setPosition(540,-100);
    sun.setFillColor(Color::Yellow);
    window.draw(sun);
}

void drawCloud (int radius, int cloudx, int cloudy, RenderWindow &window)   {
    CircleShape cloud;
    cloud.setRadius(radius);
    cloud.setFillColor(Color::White);
    int storeCloudy = cloudy;

    for(int i = 0; i < 4; ++i)  {
        cloudy = storeCloudy;
        cloud.setPosition(cloudx, cloudy);
        window.draw(cloud);

        if (i == 3) {
            break;
        }

        cloudx += radius/2;
        cloudy -= radius;
        cloud.setPosition(cloudx, cloudy);
        window.draw(cloud);

        cloudx += radius/2;
    }
}

void drawGround(RenderWindow &window)  {
    RectangleShape ground;
    ground.setPosition(0, 550);
    ground.setSize(Vector2f(640, 90));
    ground.setFillColor(Color(139, 69, 19));
    window.draw(ground);
}

void drawGrass(RenderWindow &window)    {
    RectangleShape grass;
    grass.setPosition(0, 550);
    grass.setSize(Vector2f(640, 20));
    grass.setFillColor(Color(34, 139, 34));
    window.draw(grass);
}

void drawTreeBase(RenderWindow &window) {
    RectangleShape tree;
    tree.setPosition(370, 400);
    tree.setSize(Vector2f(40, 150));
    tree.setFillColor(Color(139, 69, 19));
    window.draw(tree);
}

void drawTreeTop(RenderWindow &window)  {
    int radius = 35;
    CircleShape treeTop;
    treeTop.setRadius(radius);
    treeTop.setFillColor(Color::Green);
    int treeTopx = 338;
    int treeTopy = 370;

    int treeTopxStore = treeTopx;

    for (int i = 0; i < 2; ++i)    {
        treeTopx = treeTopxStore;

        treeTop.setPosition(treeTopx, treeTopy);
        window.draw(treeTop);

        treeTopx += radius;
        treeTop.setPosition(treeTopx, treeTopy);
        window.draw(treeTop);

        treeTopy -= radius;
    }
}
