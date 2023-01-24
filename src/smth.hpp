#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
// const
const double PI = 3.14159265358979323846;
const float JUMP_HEIGHT = 200;
const float GRAVITY = 1000;
const float maxSpeedV = 5;
// end
struct Object
{
    sf::Vector2f position;
    float angle;
    sf::Sprite sprite;
    sf::Texture texture;
};
void display_smth(Object &object, sf::RenderWindow &window)
{
    object.sprite.setPosition(object.position);
    window.draw(object.sprite);
}
void update_pos(Object &object1, Object &object2)
{
    object1.position = object2.position;
}
void moveObject_angle(Object &object, float &distance, float &angle)
{
    // Calculate the displacement in the x and y directions
    float dx = distance * cos(angle * PI / 180.0f);
    float dy = distance * sin(angle * PI / 180.0f);

    // Update the object's position
    object.position.x += dx;
    object.position.y += dy;

    // Update the object's sprite position
    object.sprite.setPosition(object.position);
}