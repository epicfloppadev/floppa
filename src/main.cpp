// Comp issues win any rez other tham 1920*1080
#include "objects.hpp"
#include "grass.cpp"
using namespace sf;
bool jumping = 0;
float jump_velocity = 0;
float accelerationV = 0.2;
float speedV = 0;
bool o_g = 0;
int main()
{
    Music battle;
    battle.openFromFile("Audio/battle.wav");
    battle.play();
    Object player, grass, bg;
    if (!player.texture.loadFromFile("Images/big-floppa-player.png") || !bg.texture.loadFromFile("Images/bluemoon.png"))
    {
        return -1;
    }
    player.init_obj("Images/big-floppa-player.png", {500, 620});
    bg.init_obj("Images/bluemoon.png", {0, 0});
    grass.init_obj("Images/grass.png", {0, 620});
    player.sprite.setScale(0.60, 0.60);
    // init_grass();
    bg.sprite.setTexture(bg.texture);
    player.sprite.setTexture(player.texture);
    platform1.texture.loadFromFile("Images/platform1.png");
    RenderWindow window(sf::VideoMode(1280, 720), "Super Floppa", Style::Titlebar | Style::Close);
    Clock clock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed || Mouse::isButtonPressed(Mouse::Right))
                window.close();
        }
        Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        /* if (Keyboard::isKeyPressed(Keyboard::A))
            player.position += {-10.f, 0.f};
        if (Keyboard::isKeyPressed(Keyboard::D))
            player.position += {10.f, 0.f};*/
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            accelerationV = 2;
            speedV += accelerationV;
            if (speedV > maxSpeedV)
                speedV = maxSpeedV;
            player.position += {-speedV, 0.f};
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            accelerationV = 2;
            speedV += accelerationV;
            if (speedV > maxSpeedV)
                speedV = maxSpeedV;
            player.position += {speedV, 0.f};
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !jumping)
        {
            jumping = 1;
            o_g = 0;
            jump_velocity = sqrt(2 * GRAVITY * JUMP_HEIGHT);
        }
        if (jumping)
        {
            if (o_g == 0)
            {
                if (!jump_velocity * dt < grass.position.y - player.position.y + player.texture.getSize().y * player.sprite.getScale().y)
                    player.position.y -= jump_velocity * dt;
                else
                {
                    o_g = 1;
                    player.position.y = grass.position.y - player.texture.getSize().y * player.sprite.getScale().y;
                }
                jump_velocity -= GRAVITY * dt;
            }
            else
                player.position.y = grass.position.y - player.texture.getSize().y * player.sprite.getScale().y;
        }
        if (colision(player, grass))
        {
            jumping = 0;
            player.position.y = grass.position.y - player.texture.getSize().y * player.sprite.getScale().y;
        }
        if (dt < 1.f / 60.f)
        {
            sleep(sf::seconds(1.f / 60.f - dt));
        }
        window.clear();
        bg.display(window);
        grass.display(window);
        player.display(window);

        window.display();
        std::cout << player.sprite.getPosition().x << '\n';
    }
    return 0;
}
