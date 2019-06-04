//
// Created by Jarod Spencer1 on 2019-04-15.
//

#ifndef SFML_TEMPLATE_FUNCTIONS_H
#define SFML_TEMPLATE_FUNCTIONS_H

#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "starDataStruct.h"

using namespace std;
using namespace sf;

void convertXPos(int, const int&, vector<StarData>&);
void convertYPos(int, const int&, vector<StarData>&);
void writeStarData(vector<StarData>&, ofstream&);
void drawStars(RenderWindow&, const int&, vector<StarData>&, const int&);

#endif //SFML_TEMPLATE_FUNCTIONS_H
