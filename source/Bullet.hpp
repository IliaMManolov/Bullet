#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable
{
    public:
        Bullet(sf::Vector2f st, sf::Vector2f d, float s);

        void update(sf::Time deltaTime);
        bool isInRange(sf::Vector2f ul, sf::Vector2f lr);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Vector2f direction;

        float speed;

        sf::RectangleShape gBullet;


        float rotation;
};




#endif // BULLET_HPP
