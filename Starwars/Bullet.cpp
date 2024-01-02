
#include <cmath>
#include <iostream>
#include "Bullet.hpp"



Bullet::Bullet(
    Animation& a, float x, float y, float angle, float radius) :
    Entity(a, x, y, angle, radius) {

    mName = BULLET;



}

void Bullet::update() {
    Entity::update();

    mDx = std::cos(mAngle * mDegtorad) * 6;
    mDy = std::sin(mAngle * mDegtorad) * 6;
    mX += mDx;
    mY += mDy;

    if (mX > mWindowWidth || mX < 0 || mY > mWindowHeight || mY < 0) {
        mIsAlive = false;
    }
}

