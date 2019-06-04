/* CSCI 261: L7A: SFML Drawing
 *
 * Author: Jarod Spencer
 *
 * Description: Introduction to SFML drawing
 */

#include <iostream>                             // for standard input/output
#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
#include "functions.h"

using namespace std;                            // using the standard namespace
using namespace sf;                             // using the sf namespace

int main() {
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );

    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame

        //all graphics go below here
        drawSun(window);
        drawCloud(26, 100, 100, window);
        drawGround(window);
        drawGrass(window);
        drawTreeBase(window);
        drawTreeTop(window);

        window.display();

        Event event;
        while( window.pollEvent(event) ) {
            if( event.type == Event::Closed ) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();
            }
        }
    }

    return EXIT_SUCCESS;
}