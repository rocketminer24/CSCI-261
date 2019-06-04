//
// Created by Jarod Spencer1 on 2019-04-27.
//

#include "Bubble.h"

using namespace std;

//default constructor
Bubble::Bubble()    {
    myBubble.setRadius(radius);
    myBubble.setPosition(xPos,yPos);
    myBubble.setFillColor(Color::White);
    xDir = 0.1;
    yDir = 0.2;
}

//function initializes a Bubble object to random characteristics within specific ranges
void Bubble::initializeBubble()    {
    xPos = (rand() % 301) + 100;
    yPos = (rand() % 301) + 100;
    xDir = (double)(rand() % 26) / 10.0;
    yDir = (double)(rand() % 26) / 10.0;
    radius = (rand() % 41) + 10;
    myBubble.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
}

//function initializes an added Bubble object to specified location and other characteristics to
//   random in their respective ranges
void Bubble::initializeNewBubble(const int &xLocation, const int &yLocation)  {
    xPos = xLocation;
    yPos = yLocation;
    xDir = (double)(rand() % 26) / 10.0;
    yDir = (double)(rand() % 26) / 10.0;
    radius = (rand() % 41) + 10;
    myBubble.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
}

//updates and sets new position of a Bubble object
void Bubble::updatePosition()   {
    xPos += xDir;
    yPos += yDir;
    myBubble.setPosition(xPos, yPos);
}

//allows user to manually set initial x direction of a Bubble object
void Bubble::setInitialXDir(const double &xDir)   {
    this->xDir = xDir;
}

//allows user to manually set initial y direction of a Bubble object
void Bubble::setInitialYDir(const double &yDir)   {
    this->yDir = yDir;
}

//draws a Bubble object in the window
void Bubble::drawBubble(RenderWindow &window) {
    window.draw(myBubble);
}

//bounces a Bubble object if it is at the edge of the window
void Bubble::bounce(const int &windowWidth, const int &windowHeight)   {
    if (xPos >= (windowWidth - (2 * radius)) || xPos <= 0)   {
        xDir = (-1) * xDir;
    }
    if (yPos >= (windowHeight - (2 * radius)) || yPos <= 0)   {
        yDir = (-1) * yDir;
    }
}