// Comp issues win any rez other tham 1920*1080
#include "smth.hpp"
#include "grass.cpp"
#include "tile.cpp"
using namespace sf;
bool jumping = 0;
float jump_velocity = 0;
float accelerationV = 0.5;
float speedV = 0;
bool o_g = 0;
int main()
{

    tile tiles[8][14];
    loadTiles(tiles);
    //
    // Music battle;
    // battle.openFromFile("Audio/battle-of-the-dragons-8037.wav");
    // battle.play();
    Object player = {{500, 500}, 0},
           bg{{1000, 1000}, 0};
    if (!player.texture.loadFromFile("Images/tile.jpg") || !bg.texture.loadFromFile("Images/bg.jpg"))
    {
        return -1;
    }
    player.sprite.setScale(0.7, 0.7);
    init_grass();
    bg.sprite.setTexture(bg.texture);
    player.sprite.setTexture(player.texture);
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

        if (Keyboard::isKeyPressed(Keyboard::A))
        {

            speedV += accelerationV;
            if (speedV > maxSpeedV)
                speedV = maxSpeedV;
            player.position += {-speedV, 0.f};
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            speedV += accelerationV;
            if (speedV > maxSpeedV)
                speedV = maxSpeedV;
            player.position += {speedV, 0.f};
        }
        else
        {
            speedV -= (-1 * bool(speedV < 0)) * accelerationV;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && !jumping)
        {
            jumping = 1;
            o_g = 0;
            jump_velocity = sqrt(2 * GRAVITY * JUMP_HEIGHT);
        }
        if (o_g == 0)
        {
            player.position.y -= jump_velocity * dt;
            jump_velocity -= GRAVITY * dt;
        }
        if (touch_grass_lol(player, grass))
        {
            jumping = 0;
            o_g = 1;
            player.position.y = grass.getPosition().y - player.texture.getSize().y * player.sprite.getScale().y;
        }
        if (dt < 1.f / 60.f)
        {
            sleep(sf::seconds(1.f / 60.f - dt));
        }

        window.clear();
        //   window.draw(bg.sprite);
        // window.draw(grass);
        for (int i = 0; i <= 6; i++)
        {
            for (int j = 0; j <= 12; j++)
            {
                if (tiles[i][j].activated == 0)
                {

                    display_tile(tiles[i][j], window);
                    // std::cout<<tiles[i][j].position.x<<' '<<tiles[i][j].position.y<<std::endl;
                }
            }
        }
        display_smth(player, window);
        window.display();
    }
    return 0;
}
