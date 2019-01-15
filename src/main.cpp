#include <SFML/Graphics.hpp>
#include <iostream>
#include "tilemap.h"
#include "inputhandler.h"

int main() {
    const int WINDOW_SIZE = 160;
    const int BOARD_SIZE = 160;
    const int NUM_TILES = 5;
    //create window for game
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Minesweeper");

    //create board
    int board[] =
            {
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0
            };

    //create tilemap
    TileMap map;
    sf::Vector2i tileSize(32, 32);
    if (!map.load("assets/ms_tiles.png", tileSize, board, NUM_TILES, NUM_TILES))
        ;

    //let's set the view so that the entire board is fit to the screen
    sf::View view(sf::FloatRect(0, 0, BOARD_SIZE, BOARD_SIZE));
    window.setView(view);

    //create InputHandler
    InputHandler input(window);
    MouseClick mClick(sf::Vector2i(), true, false);

    //keep window open until user closes it
    while (window.isOpen()) {
        sf::Event event;

        //check window events triggered since last iteration
        while (window.pollEvent(event)) {
            input.close(event);
            mClick = input.mouseClick(event);

            map.update(mClick.clicked, mClick, tileSize, board);
        }

        //reset the frame by clearing with black
        window.clear(sf::Color::Black);

        //draw the board
        window.draw(map);

        //end the frame
        window.display();
    }
    return 0;
}