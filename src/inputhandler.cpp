//
// Created by mark on 1/11/2019.
// Manages user input.
//

#include <iostream>
#include "inputhandler.h"
#include "mouseclick.h"

InputHandler::InputHandler(sf::RenderWindow &window) {
    this->window = &window;
}

InputHandler::~InputHandler() {

}

void InputHandler::close(sf::Event& event) { //checks if user closed window, if true, closes window
    if (event.type == sf::Event::Closed)
        window->close();
}

MouseClick InputHandler::mouseClick(sf::Event& event) { //returns a MouseClick object based on which mouse button is clicked
    sf::Vector2i coords(0, 0);
    MouseClick mClick(coords, true, false);

    if (event.type == sf::Event::MouseButtonPressed){
        mClick.coords.x = event.mouseButton.x;
        mClick.coords.y = event.mouseButton.y;
        mClick.clicked = true;

        if (event.mouseButton.button == sf::Mouse::Left)
            ;
        else if (event.mouseButton.button == sf::Mouse::Right)
            mClick.left = false;
    }

    return mClick;
}
