#include <SFML/Graphics.hpp>
#include "tilemap.h"

int main() {

    //create window for game
    sf::RenderWindow window(sf::VideoMode(640, 640), "Minesweeper");

    //create board
    int board[] =
            {
                    0, 1, 2,
                    3, 4, 5,
                    0, 0, 0
            };

    //create tilemap
    TileMap map;
    if (!map.load("assets/ms_tiles.png", sf::Vector2i(32, 32), board, 3, 3))
        return -1;

    //let's set the view so that the entire board is fit to the screen
    sf::View view(sf::FloatRect(0, 0, 95, 95));
    window.setView(view);

    //keep window open until user closes it
    while (window.isOpen()) {
        sf::Event event;
        //check window events triggered since last iteration
        while (window.pollEvent(event)) {
            //close window if user exits
            if (event.type == sf::Event::Closed)
                window.close();
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