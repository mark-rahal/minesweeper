//
// Created by mark on 1/11/2019.
// Used by InputHandler to manage user mouse input.
//

#include "mouseclick.h"

MouseClick::MouseClick(sf::Vector2i coords, bool left, bool clicked) {
    this->coords = coords;
    this->left = left;
    this->clicked = clicked;
}

MouseClick::~MouseClick() {

}

MouseClick& MouseClick::operator=(const MouseClick& M) { // = operator overload
    coords = M.coords;
    left = M.left;
    clicked = M.clicked;
}
