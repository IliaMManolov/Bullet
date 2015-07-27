#include <SFML/Graphics.hpp>

#include <cmath>
#include <iostream>
#include <list>

using namespace std;

class Bullet : public sf::Drawable, public sf::Transformable
{
    public:
        Bullet(sf::Vector2f st, sf::Vector2f d, float s);

        void update();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Vector2f direction;

        float speed;

        sf::RectangleShape gBullet;


        float rotation;

        sf::RectangleShape gBullet;
};

Bullet::Bullet(sf::Vector2f st = sf::Vector2f(0, 0), sf::Vector2f d = sf::Vector2f(0, 0), float s = 0.f)
: speed(s)
, gBullet(sf::Vector2f(16, 16))
{
    const float PI = 3.14159265;

    this->move(st);

    gBullet.setFillColor(sf::Color::Red);

    sf::Vector2f delta = d-st;

    float dLen = sqrt(delta.x*delta.x+delta.y*delta.y);

    direction = delta/dLen;

    rotation = (atan2(st.x - d.x, st.y - d.y)) * 180 / PI;

    gBullet.setRotation(rotation + 180);
}


void Bullet::update()
{
    this->move(direction*speed);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    target.draw(gBullet, states);
}



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







    /*float Bx = 0;
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
    }*/

    return 0;
}
