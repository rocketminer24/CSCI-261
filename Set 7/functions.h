//
// Created by Jarod Spencer1 on 2019-04-14.
//

#ifndef SFML_TEMPLATE_FUNCTIONS_H
#define SFML_TEMPLATE_FUNCTIONS_H

#include <SFML/Graphics.hpp>
using namespace sf;

void drawSun(RenderWindow &window);
void drawCloud (int radius, int cloudx, int cloudy, RenderWindow &window);
void drawGround(RenderWindow &window);
void drawGrass(RenderWindow &window);
void drawTreeBase(RenderWindow &window);
void drawTreeTop(RenderWindow &window);

#endif //SFML_TEMPLATE_FUNCTIONS_H
