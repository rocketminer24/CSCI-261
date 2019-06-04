/* CSCI 261: L8C: Bouncing Bubble
 *
 * Author: Jarod Spencer
 *
 * Description: Using SFML & classes to create a bouncing bubble animation
 */

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>

using namespace sf;

#include "Bubble.h"

int main() {
    //creates drawing window
    int windowWidth = 700;
    int windowHeight = 640;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Bouncing Bubble Window");

    //declares Bubble object bubble
    Bubble bubble;

    //draw loop
    while (window.isOpen()) {
        window.clear(Color::Black);

        //draws bubble in window
        bubble.drawBubble(window);

        //displays the window
        window.display();

        //if a closed event occurs, close the window
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        //updates the position of bubble
        bubble.updatePosition();

        //if bubble is at the edge of the window, bounces bubble
        bubble.bounce(windowWidth, windowHeight);
    }

    return EXIT_SUCCESS;
}
