#include "smth.hpp"
using namespace sf;
RectangleShape grass(Vector2f(1280.f, 100.f));
Texture grass_tex;
void init_grass()
{

    if (!grass_tex.loadFromFile("Images/grass.png"))
    {
        exit(-10239812);
    }
    grass.setTexture(&grass_tex);
    grass.setPosition(0, 620);
}
bool touch_grass_lol(Object &object, RectangleShape grass)
{
    if (object.sprite.getGlobalBounds().intersects(grass.getGlobalBounds()))
    {
        return 1;
    }
    return 0;
}
