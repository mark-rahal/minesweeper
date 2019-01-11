//
// Created by mark on 1/10/2019.
//

#include "tilemap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2i tileSize, const int* tiles, int width, int height) {

    //load tileset texture from fil
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

            //define the quad's 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
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