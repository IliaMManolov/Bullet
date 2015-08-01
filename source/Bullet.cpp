#include "Bullet.hpp"
#include <cmath>
#include <iostream>

const float PI = 3.14159265;


Bullet::Bullet(sf::Vector2f st = sf::Vector2f(0, 0), sf::Vector2f d = sf::Vector2f(0, 0), float s = 0.f)
: speed(s)
, gBullet(sf::Vector2f(16, 32))
{
    this->setOrigin(gBullet.getSize()/2.f);
    this->setPosition(st);
    gBullet.setFillColor(sf::Color::Red);

    sf::Vector2f delta = d-st;

    float dLen = sqrt(delta.x*delta.x+delta.y*delta.y);

    direction = delta/dLen;

    rotation = (atan2(st.x - d.x, st.y - d.y)) * 180 / PI;
    rotation = -rotation;

    this->setRotation(rotation + 180);
}


void Bullet::update(sf::Time deltaTime)
{
    this->move(direction*speed*deltaTime.asSeconds());
}

bool Bullet::isInRange(sf::Vector2f ul, sf::Vector2f lr)
{
    //std::cout<<ul.x<<' '<<ul.y<<' '<<lr.x<<' '<<lr.y<<' '<<this->getPosition().x<<' '<<this->getPosition().y<<std::endl;


    if (this->getPosition().x>ul.x&&this->getPosition().x<lr.x&&this->getPosition().y>ul.y&&this->getPosition().y<lr.y)
    {
        return true;
    }
    //std::cout<<"hue"<<std::endl;

    return false;
}


void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    target.draw(gBullet, states);
}
