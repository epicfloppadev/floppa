#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
// const
const double PI = 3.14159265358979323846;
const float JUMP_HEIGHT = 200;
const float GRAVITY = 1000;
const float maxSpeedV = 5;
// end
class Object
{
public:
    sf::Vector2f position;
    float angle;
    sf::Sprite sprite;
    sf::Texture texture;

    void display(sf::RenderWindow &window)
    {
        sprite.setPosition(position);
        window.draw(sprite);
    }
    bool init_obj(std::string, sf::Vector2f);
};
bool Object::init_obj(std::string file_name, sf::Vector2f set_position)
{
    if (!texture.loadFromFile(file_name))
    {
        return 0;
    }
    else
    {
        sprite.setTexture(texture);
        position = set_position;
        return 1;
    }
}
