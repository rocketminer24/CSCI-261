//
// Created by Jarod Spencer1 on 2019-04-27.
//

#ifndef SFML_TEMPLATE_BUBBLE_H
#define SFML_TEMPLATE_BUBBLE_H


#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Bubble {
public:
    Bubble();
    void initializeBubble();
    void initializeNewBubble(const int&, const int&);
    void updatePosition();
    void setInitialXDir(const double &xDir);
    void setInitialYDir(const double &yDir);
    void drawBubble(RenderWindow&);
    void bounce(const int&, const int&);
private:
    int radius = 50;
    double xPos = 50;
    double yPos = 0;
    CircleShape myBubble;
    double xDir;
    double yDir;
};

#endif //SFML_TEMPLATE_BUBBLE_H
