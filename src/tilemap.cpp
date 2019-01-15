//
// Created by mark on 1/10/2019.
// Creates the game board from the tileset and map data. Updates the board from MouseClick.
//

#include <iostream>
#include "tilemap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2i tileSize, const int* tiles, int width, int height) {

    //load tileset texture from file
    if (!mTileset.loadFromFile(tileset))
        return false;

    //set vertex array size to game board size
    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(width * height * 4);

    //fill the vertex array with tiles (1 quad = 1 tile)
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++) {
            //get state of current tile
            int tileState = tiles[i + (j * width)];

            //find its position in the tileset texture
            int tx = tileState % (mTileset.getSize().x / tileSize.x);
            int ty = tileState / (mTileset.getSize().x / tileSize.x);


            //get pointer to the current tile's quad
            sf::Vertex* quad = &mVertices[(i + (j * width)) * 4];
            std::cout << "Vertex number: " << (i + (j * width)) * 4 << std::endl;

            //define the quad's 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            std::cout << "Coords: " << i * tileSize.x << " " << j * tileSize.y << std::endl;
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            std::cout << "Coords: " << (i + 1) * tileSize.x << " " << j * tileSize.y << std::endl;
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            //define the texure's 4 corners from the tileset
            quad[0].texCoords = sf::Vector2f(tx * tileSize.x, ty * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tx + 1) * tileSize.x, ty * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tx + 1) * tileSize.x, (ty + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tx * tileSize.x, (ty + 1) * tileSize.y);
        }
    }

    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {

        //apply transform
        states.transform *= getTransform();

        //apply tileset texture
        states.texture = &mTileset;

        //draw vertex array
        target.draw(mVertices, states);
}

//updates the game board
void TileMap::update(bool clicked, const MouseClick& mClick, sf::Vector2i tileSize, int* tiles) {
    //player clicked
    if (!clicked) {
        return;
    }
    //player left clicked
    else if (mClick.left) {
        int tileNum = getTileNum(mClick.coords, tileSize);

        tiles[tileNum / 4] = 1;
        updateTile(tiles[tileNum / 4], tileNum, tileSize);
    }
    //player right clicked
    else {
        ;
    }
}

//this function allows us to get the index of a tile in our vertex array from a coordinate inside the tile
int TileMap::getTileNum(sf::Vector2i coords, sf::Vector2i tileSize) {
    int clickX = static_cast<int>(coords.x);
    int clickY = static_cast<int>(coords.y);

    return ((clickX / tileSize.x) * 4) + ((clickY / tileSize.y) * 20);
}

//this function allows us to update a tile in the vertex array
void TileMap::updateTile(int state, int index, sf::Vector2i tileSize) {

    //quad to update
    sf::Vertex* quad = &mVertices[index];

    //find new texture position in the tileset texture
    int tx = state % (mTileset.getSize().x / state);
    int ty = state / (mTileset.getSize().x / tileSize.x);

    //update the coords of the tile's texture
    quad[0].texCoords = sf::Vector2f(tx * tileSize.x, ty * tileSize.y);
    quad[1].texCoords = sf::Vector2f((tx + 1) * tileSize.x, ty * tileSize.y);
    quad[2].texCoords = sf::Vector2f((tx + 1) * tileSize.x, (ty + 1) * tileSize.y);
    quad[3].texCoords = sf::Vector2f(tx * tileSize.x, (ty + 1) * tileSize.y);
}