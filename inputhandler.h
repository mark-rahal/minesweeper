//
// Created by mark on 1/11/2019.
// Manages user input.
//

#ifndef MINESWEEPER_INPUTHANDLER_H
#define MINESWEEPER_INPUTHANDLER_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "mouseclick.h"

class InputHandler {
private:
    sf::RenderWindow* window; //gives InputHandler access to the window
public:
    explicit InputHandler(sf::RenderWindow&);
    ~InputHandler();
    void close(sf::Event&);
    MouseClick mouseClick(sf::Event&);
};


#endif //MINESWEEPER_INPUTHANDLER_H
