//
// Created by mark on 1/10/2019.
// Creates the game board from the tileset and map data. Updates the board from MouseClick.
//

#ifndef MINESWEEPER_TILEMAP_H
#define MINESWEEPER_TILEMAP_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "mouseclick.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string&, sf::Vector2i, const int*, int, int); //allows us to load the map data from a file
    void update(bool, const MouseClick&, sf::Vector2i, int* tiles); //update the map
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const; //allows us to render the map using the draw() method
    int getTileNum(sf::Vector2i, sf::Vector2i); //get index of a tile in a vertex array from a coord in the tile
    void updateTile(int, int, sf::Vector2i); //update a tile in the vertex array
    sf::VertexArray mVertices;
    sf::Texture mTileset;
};


#endif //MINESWEEPER_TILEMAP_H
