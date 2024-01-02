#include "Animation.hpp"


Animation::Animation(
    const sf::Texture& t, int x, int y, int width, int height, int count, float speed) :
    mFrame(0), mSpeed(speed) {
    //mframes is to store individual images of the sprite sheet, count is total number of images in the sprite sheet//speed represents animation switch time//width and heigth represents the width and height of the part of the total image//x and y represents the coordinates of the selected image within the image//mframe used to specify the index of the image//
    for (int i = 0; i < count; i++) {
        mFrames.push_back(sf::IntRect(x + i * width, y, width, height));//images are horizontal so only x coordinate is updated while y remains the same
    }

    mSprite.setTexture(t);
    mSprite.setOrigin(width / 2.f, height / 2.f);
    mSprite.setTextureRect(mFrames[0]);//setting texture to the frame of the image selected
}

void Animation::update() {
    mFrame += mSpeed;//increasing frame index with speed
    auto n = mFrames.size();//mframes.size() gives number of images of the sprite sheet stored
    if (mFrame >= n) {
        mFrame -= n; //if index becomes greator than no of images then decrease
    }
    if (n > 0) {
        mSprite.setTextureRect(mFrames[static_cast<int>(mFrame)]);//speed is float but index has to be int
    }
}//from start of sprite sheet to end it keeps moving back and forth once sprite sheet is completed

bool Animation::isEnd() {
    return mFrame + mSpeed >= mFrames.size();//current index of image+speed of switching is greator than no of images
}//used for explosion only because explosion has to end where as asteriods keep moving

