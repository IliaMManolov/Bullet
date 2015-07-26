#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "mouse shooting");
    window.setFramerateLimit(60);

    sf::RectangleShape player(sf::Vector2f(32, 32));
    sf::RectangleShape bullet(sf::Vector2f(16, 16));

    float Bx = 0;
    float By = 0;

    float Mx = 0;
    float My = 0;

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
}
