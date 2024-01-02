#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class Animation {
private:
    float mFrame, mSpeed;
    sf::Sprite mSprite;
    std::vector<sf::IntRect> mFrames;//used to define a rectangle at specified coordinates with specific size


public:
    Animation() {};
    Animation(const sf::Texture& t, int x, int y, int width, int height, int count, float speed);

    sf::Sprite sprite() { return mSprite; }
    void update();
    bool isEnd();
};

