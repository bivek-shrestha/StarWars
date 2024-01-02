

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class Menu
{
public:
    Menu();
    ~Menu();

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

    bool options;
    bool esc;
    bool play;
    sf::Texture background;
    sf::Sprite backgroundsp;
    sf::Texture opbackground;
    sf::Sprite opbackgrounds;
    sf::Text opt;
    int height = 1100;
    int width = 1960;



private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text title;



};

