#pragma once
#include "Entity.hpp"


class Player : public Entity {
private:

    bool mThrust = false;
    const float mAcceleration = 0.17f;
    const float mMaxSpeed = 12.f;
    const float mDrag = 0.99f;
    const float mDegtorad = 0.017453f;
    float speed;

public:
    Player() {};
    Player(Animation& a, float x, float y, float angle = 0.f, float radius = 1.f);

    int mNumLives = 5;
    bool thrust() { return mThrust; }
    void setThrust(bool thrust) { mThrust = thrust; }
    int lives() { return mNumLives; }
    void setLives(int lives) { mNumLives = lives; }



    void reset(Animation& a, float x, float y, float angle);

    void update() override;

};

