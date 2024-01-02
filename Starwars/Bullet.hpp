
#pragma once
#include "Entity.hpp"


class Bullet : public Entity {
private:
    const float mDegtorad = 0.017453f;


public:
    Bullet(Animation& a, float x, float y, float angle = 0.f, float radius = 1.f);

    void update() override;
};

