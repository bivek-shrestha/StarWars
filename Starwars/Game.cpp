#include <iostream>
#include "Game.hpp"




bool Game::isCollide(Entity* a, Entity* b) {
    return std::pow((b->x() - a->x()), 2) +
        std::pow((b->y() - a->y()), 2) <
        std::pow((a->radius() + b->radius()), 2);
}

void Game::initialize() {

    mWindow.setFramerateLimit(60);


    mPlayerTexture.loadFromFile("images/spaceship.png");
    mBackgroundTexture.loadFromFile("images/backgroundgame.jpg");
    mExplosionTexture.loadFromFile("images/explosions/type_C.png");
    mRockTexture.loadFromFile("images/rock.png");
    mBulletTexture.loadFromFile("images/fire_blue.png");
    mSmallRockTexture.loadFromFile("images/rock_small.png");
    mShipExplosionTexture.loadFromFile("images/explosions/type_B.png");

    mPlayerTexture.setSmooth(true);
    mBackgroundTexture.setSmooth(true);


    mBackground.setTexture(mBackgroundTexture);
    shoot.loadFromFile("sounds/gunsound.wav");
    shoots.setBuffer(shoot);
    explosion.loadFromFile("sounds/explosionsound.wav");
    explosions.setBuffer(explosion);



    for (int i = 0; i < 15; i++)
    {

        Asteroid* a = new Asteroid(mRockAnimation, rand() % mWindowWidth, rand() % mWindowHeight, rand() % 360, 25);
        mEntities.push_back(a);
    }



    mEntities.push_back(mPlayer);



    if (!mFont.loadFromFile("fonts/SFDistantGalaxy.ttf")) {
        std::cerr << "Error loading font\n";

    }
    playerScore = 0;

    mLivesText.setFont(mFont);
    mLivesText.setCharacterSize(50);
    mLivesText.setFillColor(sf::Color::White);
    mLivesText.setString("LIVES LEFT: " + std::to_string(mPlayer->lives()));

    mScoreText.setFont(mFont);
    mScoreText.setCharacterSize(50);
    mScoreText.setFillColor(sf::Color::White);
    mScoreText.setString("PRESS ESC FOR MENU \n SCORE: " + std::to_string(playerScore));
    mScoreText.setPosition(0, 40);

    mGameOverText.setFont(mFont);
    mGameOverText.setCharacterSize(100);
    mGameOverText.setFillColor(sf::Color::White);
    mGameOverText.setPosition(mWindowWidth / 4, mWindowHeight / 4);




}



void Game::handleEvents() {

    while (mWindow.pollEvent(event)) {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
            case (sf::Keyboard::Up):
                m.MoveUp();

                break;

            case (sf::Keyboard::Down):
                m.MoveDown();
                break;

            case (sf::Keyboard::Return):
                switch (m.GetPressedItem())
                {
                case 0:

                    m.play = true;

                    break;
                case 1:

                    m.options = true;
                    break;
                case 2:
                    mWindow.close();

                    break;
                }

                break;
            }

            break;
        case sf::Event::Closed:
            mWindow.close();


            break;



        }


        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
            {
               

                {
                    mPlayer->setAlive(false);
                    
                    m.esc = true;
                    if (m.esc == true)
                   {
                       reset();
                       m.esc = false;
                    }
                       

                    m.options = false;
                    m.play = false;
                }
                

            }
        }
        if (event.key.code == sf::Keyboard::Space) {
            if (mPlayer->isAlive()) {
                Bullet* b = new Bullet(mBulletAnimation, mPlayer->x(), mPlayer->y(), mPlayer->angle(), 10);
                mEntities.push_back(b);
                shoots.play();
            }
        }
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mPlayer->setAngle(mPlayer->angle() + 3);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mPlayer->setAngle(mPlayer->angle() - 3);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        mPlayer->setThrust(true);
    }
    else {
        mPlayer->setThrust(false);
    }
}
void Game::handleCollisions() {
    for (auto a : mEntities) {
        for (auto b : mEntities) {
            if (a->name() == ASTEROID && b->name() == BULLET) {
                if (isCollide(a, b)) {
                    a->setAlive(false);
                    b->setAlive(false);

                    Entity* e = new Entity(mExplosionAnimation, a->x(), a->y());
                    e->setName(EXPLOSION);
                    mEntities.push_back(e);
                    explosions.play();//add sound

                    if (mPlayer->isAlive()) {
                        if (a->radius() == 15) {
                            playerScore += 20;
                        }
                        else {
                            playerScore += 10;
                        }
                        mScoreText.setString("PRESS ESC FOR MENU \n SCORE: " + std::to_string(playerScore));
                    }

                    for (int i = 0; i < 2; i++) {
                        if (a->radius() == 15) {
                            continue;
                        }
                        Entity* e = new Asteroid(mSmallRockAnimation, a->x(), a->y(), rand() % 360, 15);
                        mEntities.push_back(e);
                    }

                }//split the big rock into 2 small rocks
            }

            if (a->name() == PLAYER && b->name() == ASTEROID) {
                if (isCollide(a, b)) {
                    b->setAlive(false);

                    Entity* e = new Entity(mShipExplosionAnimation, a->x(), a->y());
                    e->setName(EXPLOSION);
                    mEntities.push_back(e);
                    explosions.play();//add sound

                    mPlayer->reset(mPlayerAnimation, mWindowWidth / 2, mWindowHeight / 2, 0);

                    mPlayer->setLives(mPlayer->lives() - 1);
                    mLivesText.setString(" Lives left: " + std::to_string(mPlayer->lives()));
                    if (mPlayer->lives() <= 0) {

                        mPlayer->setAlive(false);

                        mGameOverText.setString("GAME OVER\n\nPRESS ESC FOR MENU\n\nFINAL SCORE: " + std::to_string(playerScore));
                        mLivesText.setString("");
                        mScoreText.setString("");

                    }




                }
            }
        }
    }
}

void Game::reset()

{



    for (auto i = mEntities.begin(); i != mEntities.end();)
    {
       Entity* e = *i;
       i = mEntities.erase(i);
      

    }
    for (int i = 0; i < 14; i++)
    {

        Asteroid* a = new Asteroid(mRockAnimation, rand() % mWindowWidth, rand() % mWindowHeight, rand() % 360, 25);
        mEntities.push_back(a);
    }

    mEntities.push_back(mPlayer);

    mPlayer->reset(mPlayerAnimation, mWindowWidth / 2, mWindowHeight / 2, 0);

    mPlayer->setLives(5);

    mLivesText.setString("LIVES LEFT: " + std::to_string(5));

    playerScore = 0;

    mScoreText.setString("PRESS ESC FOR MENU \n SCORE: " + std::to_string(0));


}

void Game::update() {

    if (mPlayer->thrust()) {
        mPlayer->setAnimation(mPlayerGoAnimation);
    }
    else {
        mPlayer->setAnimation(mPlayerAnimation);
    }


    for (auto e : mEntities) {
        if (e->name() == EXPLOSION) {
            if (e->animation().isEnd()) {
                e->setAlive(false);
            }
        }
    }


    if (rand() % 160 == 0) {
        Asteroid* a = new Asteroid(mRockAnimation, 0, rand() % mWindowHeight, rand() % 360, 25);
        mEntities.push_back(a);
    }

    for (auto i = mEntities.begin(); i != mEntities.end();) {
        Entity* e = *i;

        e->update();

        if (!e->isAlive()) {
            i = mEntities.erase(i);
        }
        else {
            i++;
        }
    }
}

void Game::draw() {

    mWindow.clear();
    mWindow.draw(mBackground);
    for (auto i : mEntities) {
        i->draw(mWindow);
    }

    mWindow.draw(mScoreText);
    mWindow.draw(mLivesText);
    if ((mPlayer->lives() <= 0)) {
        mPlayer->setAlive(false);
        mWindow.clear();
        mWindow.draw(mBackground);
        mWindow.draw(mGameOverText);

    }

    mWindow.display();


}




void Game::run() {

    initialize();


    while (mWindow.isOpen()) {

        handleEvents();

        if (m.options == true and m.esc == false)
        {

            mWindow.clear();
            mWindow.draw(m.opbackgrounds);
            mWindow.draw(m.opt);
            mWindow.display();
            mPlayer->setAlive(false);


        }
        else if (m.play == true and m.esc == false)
        {

            mPlayer->setAlive(true);
            handleCollisions();
            update();
            draw();

        }

        else
        {
            mWindow.clear();
            m.draw(mWindow);
            mWindow.display();
            m.esc = false;
            mPlayer->setAlive(false);

        }//update draw display
    }

}

