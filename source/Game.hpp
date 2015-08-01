#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"


class Game
{
    public:
        Game();
        void run();

    private:
        void handleEvents();
        void update(sf::Time deltaTime);
        void render();


        void updateBullets(sf::Time deltaTime);


        void updateStatistics(sf::Time elapsedTime);

        sf::RenderWindow mWindow;

        const sf::Time TimePerFrame;
        sf::Font mFont;
		sf::Text mStatisticsText;
		sf::Time mStatisticsUpdateTime;
		unsigned int mStatisticsNumFrames;





        std::vector<Bullet> mBullets;


};



#endif // GAME_HPP
