#include <cmath>
#include "Player.hpp"



Player::Player(
    Animation& a, float x, float y, float angle, float radius) :
    Entity(a, x, y, angle, radius) {

    mName = PLAYER;

    mDx = 0;
    mDy = 0;
    speed = 0;
}


void Player::reset(Animation& a, float x, float y, float angle) {
    mAnimation = a;
    mX = x;
    mY = y;
    mAngle = angle;
    mDx = 0;
    mDy = 0;
    speed = 0;

}

void Player::update() {
    Entity::update();

    if (mThrust) {
        mDx += std::cos(mAngle * mDegtorad) * mAcceleration;
        mDy += std::sin(mAngle * mDegtorad) * mAcceleration;
    }
    else {
        mDx *= mDrag;
        mDy *= mDrag;
    }

    float speed = std::sqrt(mDx * mDx + mDy * mDy);
    if (speed > mMaxSpeed) {
        mDx *= mMaxSpeed / speed;
        mDy *= mMaxSpeed / speed;
    }

    mX += mDx;
    mY += mDy;

    if (mX > mWindowWidth) {
        mX = 0;
    }
    if (mX < 0) {
        mX = mWindowWidth;
    }
    if (mY > mWindowHeight) {
        mY = 0;
    }
    if (mY < 0) {
        mY = mWindowHeight;
    }
}
