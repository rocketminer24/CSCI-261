//
// Created by Jarod Spencer1 on 2019-04-20.
//

#include "Bubble.h"

//default constructor
Bubble::Bubble()    {
    myBubble.setRadius(radius);
    myBubble.setPosition(xPos,yPos);
    myBubble.setFillColor(Color::White);
    xDir = 0.1;
    yDir = 0.2;
}

//updates and sets the position of a Bubble object
void Bubble::updatePosition()   {
    xPos += xDir;
    yPos += yDir;
    myBubble.setPosition(xPos, yPos);
}

//allows the user to manually set the initial x direction of a Bubble object
void Bubble::setInitialXDir(const double &xDir)   {
    this->xDir = xDir;
}

//allows the user to manually set the initial y direction of a Bubble object
void Bubble::setInitialYDir(const double &yDir)   {
    this->yDir = yDir;
}

//draws a Bubble object in the window
void Bubble::drawBubble(RenderWindow &window) {
    window.draw(myBubble);
}

//bounces a bubble object if it is at the edge of the window
void Bubble::bounce(const int &windowWidth, const int &windowHeight)   {
    if (xPos >= (windowWidth - (2 * radius)) || xPos <= 0)   {
        xDir = (-1) * xDir;
    }
    if (yPos >= (windowHeight - (2 * radius)) || yPos <= 0)   {
        yDir = (-1) * yDir;
    }
}