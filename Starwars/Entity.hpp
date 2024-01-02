#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
//why have we used namespace ? because the names of variables repeat and we want to specify which variable we referring to.

enum eName { ASTEROID, PLAYER, BULLET, EXPLOSION };
class Entity {
protected:
    int mWindowHeight = 1100;
    int mWindowWidth = 1960;
    float mX, mY, mDx, mDy, mR, mAngle;//x and y position,dx(change in x),dy(change in y), r radius of entity
    bool mIsAlive;
    //whether entity alive or not
    eName mName;//enumeration object declared above
    Animation mAnimation;//animation object


public:
    Entity() {};
    Entity(Animation& a, float x, float y, float angle = 0.f, float radius = 1.f)
        : mX(x), mY(y), mAngle(angle), mR(radius), mIsAlive(true), mAnimation(a) {}//initializing using constructor

    float x() { return mX; }
    float y() { return mY; }
    float radius() { return mR; }
    float angle() { return mAngle; }
    bool isAlive() { return mIsAlive; }
    eName name() { return mName; }
    Animation animation() { return mAnimation; }

    void setAngle(float angle) { mAngle = angle; }
    void setAlive(bool alive) { mIsAlive = alive; }
    void setName(eName name) { mName = name; }
    void setAnimation(Animation& a) { mAnimation = a; }

    virtual void update() { mAnimation.update(); };//update animation
    void draw(sf::RenderWindow& app);

    virtual ~Entity() = default;//
};

