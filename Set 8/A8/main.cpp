/* CSCI 261: A8: Bubble Bobble
 *
 * Author: Jarod Spencer
 *
 * Description: Using SFML & classes to create a bouncing bubble animation where the
 *   user can add/delete bubbles
 */

#include <iostream>
#include <vector>

using namespace std;

#include <SFML/Graphics.hpp>

using namespace sf;

#include "Bubble.h"

int main() {
    //seeds random function
    srand(time(0));

    //creates drawing window
    int windowWidth = 700;
    int windowHeight = 640;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Bouncing Bubble Window");

    //declares vector of bubbles
    vector<Bubble> bubbles(5);

    //initializes each bubble in bubbles vector
    for (int i = 0; i < bubbles.size(); ++i) {
        bubbles[i].initializeBubble();
    }

    //draw loop
    while (window.isOpen()) {
        window.clear(Color::Black);

        //draws each bubble in bubbles vector
        for (int i = 0; i < bubbles.size(); ++i)    {
            bubbles[i].drawBubble(window);
        }

        //displays the window
        window.display();

        //event handling
        Event event;
        while (window.pollEvent(event)) {
            //since pressing d or D key is considered a closed event, must break out of loop
            //   if no bubbles in bubbles vector so window won't close. else pressing d or D
            //   will delete last bubble in vector
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::D)  {
                    if (bubbles.empty()) {
                        break;
                    } else {
                        bubbles.pop_back();
                    }
                }
            }
            //if closed event occurs (not a d or D key press), close the window
            if (event.type == Event::Closed) {
                window.close();
            }
            //if mouse was pressed, add a new bubble at that location but otherwise initialize as normal
            if (event.type == Event::MouseButtonPressed)    {
                Bubble newBubble;
                newBubble.initializeNewBubble(event.mouseButton.x, event.mouseButton.y);
                bubbles.push_back(newBubble);
            }
        }

        //update the position of all bubbles in bubbles vector
        for (int i = 0; i < bubbles.size(); ++i)    {
            bubbles[i].updatePosition();
        }

        //bounce all bubbles that are at the edge of the window
        for (int i = 0; i < bubbles.size(); ++i)    {
            bubbles[i].bounce(windowWidth, windowHeight);
        }
    }

    return EXIT_SUCCESS;
}
