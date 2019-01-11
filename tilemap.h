//
// Created by mark on 1/10/2019.
//

#ifndef MINESWEEPER_TILEMAP_H
#define MINESWEEPER_TILEMAP_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string&, sf::Vector2i, const int*, int, int); //allows us to load the map data from a file
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const; //allows us to render the map using the draw() method
    sf::VertexArray mVertices;
    sf::Texture mTileset;
};


#endif //MINESWEEPER_TILEMAP_H
