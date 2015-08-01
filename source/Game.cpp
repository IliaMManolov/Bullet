#include "Game.hpp"
#include "StringHelper.hpp"
#include <iostream>

Game::Game()
: mWindow(sf::VideoMode(800, 600), "Bullet", sf::Style::Default, sf::ContextSettings(0, 0, 2, 0))
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
, TimePerFrame(sf::seconds(1.f/60.f))
{
    mBullets.clear();

    mFont.loadFromFile("Resources/Fonts/Akashi.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			handleEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::handleEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f hue(sf::Mouse::getPosition(mWindow).x, sf::Mouse::getPosition(mWindow).y);
                    mBullets.push_back(Bullet(sf::Vector2f(400, 300),  hue, 200.f));
                }
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    updateBullets(deltaTime);
}

void Game::render()
{
    mWindow.clear();

    //draw stuff here

    for (int i=0; i<mBullets.size(); i++)
        mWindow.draw(mBullets[i]);

    mWindow.draw(mStatisticsText);

    mWindow.display();
}




void Game::updateBullets(sf::Time deltaTime)
{
    sf::Vector2f ul = sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y);
    sf::Vector2f lr = sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y);

    ul = -ul;
    lr = 2.f*lr;


    for (int i=0;i<mBullets.size();i++)
        mBullets[i].update(deltaTime);

    for (int i=0;i<mBullets.size();i++)
    {
        if (mBullets[i].isInRange(ul, lr)==false)
        {
            mBullets.erase(mBullets.begin()+i);
            i--;
        }
    }


    std::cout<<mBullets.size()<<std::endl;
}
