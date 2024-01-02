#pragma once
#include <random>
#include "Entity.hpp"


class Asteroid : public Entity {
private:



public:
    Asteroid(Animation& a, float x, float y, float angle = 0.f, float radius = 1.f);

    void update() override;
};

