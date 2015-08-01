#include "Game.hpp"



int main()
{
    Game game;
    game.run();

    return 0;
}








/*#include <SFML/Graphics.hpp>

#include <cmath>
#include <iostream>
#include <list>

using namespace std;



vector<Bullet> vBullet;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "mouse shooting");
    window.setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f hue(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                        vBullet.push_back(Bullet(sf::Vector2f(400, 300),  hue, 5.f));
                    }
                    break;
            }
        }

        for (int i=0;i<vBullet.size();i++)
        {
            vBullet[i].update();

            sf::Vector2f tmp = vBullet[i].getPosition();

            if (tmp.x<-800||tmp.x>1600||tmp.y<-600||tmp.y>1200)
            {
                vBullet.erase(vBullet.begin()+i); i--;
            }
        }

        window.clear();

        for (int i=0;i<vBullet.size();i++)
        {
            window.draw(vBullet[i]);
        }

        window.display();

    }







    float Bx = 0;
    float By = 0;

    float Mx = 0;
    float My = 0;

    int test = 0;

    float distance = 0;

    sf::Vector2f delta(Mx - Bx, My - By);
    sf::Vector2f normdelta(delta.x / distance, delta.y / distance);

    bool fired = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-2, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(2, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0, -2);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0, 2);
        }
        Bx = bullet.getPosition().x;
        By = bullet.getPosition().y;

        Mx = sf::Mouse::getPosition(window).x;
        My = sf::Mouse::getPosition(window).y;

        delta = sf::Vector2f(Mx - Bx, My - By);

        distance = sqrt(delta.x * delta.x + delta.y * delta.y);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            bullet.setPosition(player.getPosition().x, player.getPosition().y);

            normdelta = sf::Vector2f(delta.x / distance, delta.y / distance);

            fired = true;
        }
        if(fired == true)
        {
            bullet.move(normdelta.x * 20, normdelta.y * 20);
        }

        window.clear();
        window.draw(player);
        window.draw(bullet);
        window.display();
    }

    return 0;
}*/
