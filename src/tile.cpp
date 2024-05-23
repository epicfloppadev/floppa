#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class tile
{
public:
    bool activated = 0;
    Vector2f position={0.f,0.f};
    Sprite sprite;
    Texture texture;
};
Texture bgtex;
void loadTiles(tile tiles[][14])
{
    bgtex.loadFromFile("Images/tile.jpg");
    for (int i = 0; i <= 12; i++)
    {
        tiles[6][i].activated = 1;
    }
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 13; j++)
        {
            tiles[i][j].position={float(100*i), float(100*j)};
            tiles[i][j].sprite.setPosition(tiles[i][j].position);
            if (tiles[i][j].activated == 1)
            {
                tiles[i][j].sprite.setTexture(bgtex);
                
            }
        }
    }
}
void display_tile(tile &object, sf::RenderWindow &window)
{
    
    window.draw(object.sprite);
}