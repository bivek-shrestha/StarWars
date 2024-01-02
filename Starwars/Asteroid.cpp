
#include "Asteroid.hpp"


Asteroid::Asteroid(Animation& a, float x, float y, float angle, float radius) :
    Entity(a, x, y, angle, radius) {

    mName = ASTEROID;

    mDx = rand() % 8 - 4;
    mDy = rand() % 8 - 4;

}

void Asteroid::update() {
    Entity::update();//update animation

    mX += mDx;
    mY += mDy;

    if (mX > mWindowWidth) {
        mX = 0.f;
    }
    if (mX < 0.f) {
        mX = mWindowWidth;
    }
    if (mY > mWindowHeight) {
        mY = 0.f;
    }
    if (mY < 0.f) {
        mY = mWindowHeight;
    }
}

