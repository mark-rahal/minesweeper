//
// Created by mark on 1/11/2019.
// Used by InputHandler to manage user mouse input.
//

#ifndef MINESWEEPER_CLICK_H
#define MINESWEEPER_CLICK_H


#include <SFML/System.hpp>

class MouseClick {
private:
public:
    MouseClick(sf::Vector2i, bool, bool);
    ~MouseClick();
    sf::Vector2i coords;
    bool left;
    bool clicked;
    MouseClick& operator= (const MouseClick&);
};


#endif //MINESWEEPER_CLICK_H
