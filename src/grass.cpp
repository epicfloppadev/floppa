#include "objects.hpp"
using namespace sf;
Object platform1;
Texture grass_tex;
bool colision(Object &object, Object &grass)
{
    if (object.sprite.getGlobalBounds().intersects(grass.sprite.getGlobalBounds()))
    {
        return 1;
    }
    return 0;
}
