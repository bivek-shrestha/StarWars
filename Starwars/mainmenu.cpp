
#include<iostream>
#include "mainmenu.hpp"





Menu::Menu()

{

    options = false;
    esc = false;
    play = false;

    background.loadFromFile("images/backgroundmenu10.jpg");
    backgroundsp.setTexture(background);
    opbackground.loadFromFile("images/backgroundmenu.jpeg");
    opbackgrounds.setTexture(opbackground);
    

    opt.setFont(font);
    opt.setFillColor(sf::Color::White);
    opt.setString("PRESS UP, DOWN, LEFT, RIGHT  \n  \n KEYS TO NAVIGATE THE SHIP \n \n \n PRESS SPACE TO SHOOT \n \n PRESS ESC FOR MENU");
    opt.setCharacterSize(100);
    opt.setPosition(sf::Vector2f(width / 10, height / 8));





    if (!font.loadFromFile("fonts/SFDistantGalaxy.ttf"))
    {
        std::cout << "Failed to load font";
    }


    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("NEW GAME");
    menu[0].setCharacterSize(75);

    menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.7));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("OPTIONS");
    menu[1].setCharacterSize(75);
    menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.4));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("EXIT");
    menu[2].setCharacterSize(75);
    menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));



    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(backgroundsp);
    window.draw(title);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
