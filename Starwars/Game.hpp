#pragma once


#include "Animation.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Audio.hpp>
#include "mainmenu.hpp"
#include <list>
#include <time.h>

class Game {
private:

    std::list<Entity*> mEntities;

    int mWindowHeight = 1960;
    int mWindowWidth = 1100;
    Menu m;
    int playerScore;
    Player* mPlayer = new Player(mPlayerAnimation, mWindowWidth / 2, mWindowHeight / 2, 0, 25);


private:
    sf::Texture mPlayerTexture, mBackgroundTexture, mExplosionTexture,
        mRockTexture, mBulletTexture, mSmallRockTexture, mShipExplosionTexture;
    sf::Sprite mBackground;
    Animation mExplosionAnimation{ mExplosionTexture, 0, 0, 256, 256, 48, 0.5f };
    Animation mRockAnimation{ mRockTexture, 0, 0, 64, 64, 16, 0.2f };
    Animation mSmallRockAnimation{ mSmallRockTexture, 0, 0, 64, 64, 16, 0.2f };
    Animation mBulletAnimation{ mBulletTexture, 0, 0, 32, 64, 16, 0.8f };
    Animation mPlayerAnimation{ mPlayerTexture, 40, 0, 40, 40, 1, 0 };
    Animation mPlayerGoAnimation{ mPlayerTexture, 40, 40, 40, 40, 1, 0 };
    Animation mShipExplosionAnimation{ mShipExplosionTexture, 0, 0, 192, 192, 64, 0.5f };





private:
    sf::Font mFont;
    sf::Text mLivesText;
    sf::Text mScoreText;
    sf::Text mGameOverText;
    sf::SoundBuffer shoot;//text
    sf::Sound shoots;//sprite
    sf::SoundBuffer explosion;
    sf::Sound explosions;
    sf::Event event;

private:

    bool isCollide(Entity* a, Entity* b);
    void handleEvents();
    void handleCollisions();
    void update();
    void draw();
    void menuevents();
    void reset();
    void initialize();


public:

    sf::RenderWindow mWindow{
        sf::VideoMode{static_cast<unsigned int>(mWindowWidth), static_cast<unsigned int>(mWindowHeight) }, "StarWars" };
    Game(int width, int height) : mWindowWidth(width), mWindowHeight(height) {}

    void run();


};

