# StarWars
Asteroid game made using C++

# Introduction 
The player is represented by a spaceship on the screen. The player controls the ship by using the left and right arrow keys to move left and right and the up arrow key to move upwards. There are no brakes and to slow down so the player must apply the thrusters to counteract the existing velocity. The spaceship also fires bullets to destroy the asteroid in its path through the spacebar key. 

# Classes and Fuctions used
# Main file:
 main.cpp: creates an object of Game class i.e game and calls game.run() 
Game Class:
Functions: 
Game(int width , int height): Game class constructor which takes in the window width and height as parameters.
void initialize(): initializes textures, asteroids , player, score and lives.
void reset(): resets the player , score , lives and asteroids.
bool isCollide(Entity *a, Entity *b) : checks for collision between entities.
void handleEvents(): checks for keyboard inputs, allows switching between different options on the main menu, creates bullets on spacebar, rotates the player on left and right arrow keys and sets thrust to true on up arrow key.
void handleCollisions(): checks for collision between entities and create explosion at collision site, updates score , lives of player , and resets player to original position when a life is lost
void update(): ends the explosion , creates new asteroids and calls the update function of every entity 
void draw(): draws the background, the entities , score, lives, and gameover text onto the screen
Void run(): initializes, handles events, handles collisions , updates and then draws all while the window is open.


# Menu class:
Functions:
Menu(): sets the background, the fonts and text representing the choices to be displayed on the menu.
 void MoveUp(): sets a different color to the selected choice while upward movement 
 void MoveDown(): sets a different color to the selected choice while downward movement
void draw(sf::RenderWindow& window): draws background , title and menu choices onto the window.
 int GetPressedItem(): returns selected choice’s index.
# Entity class 
Functions:
Entity( Animation & a, float x, float y, float angle = 0.f, float radius= 1.f) : initializes values.
 float x() : returns x position of entity 
 float y()  : returns y position of entity
float radius() : returns radius of entity 
 float angle() : returns angle at which the entity is placed
 bool isAlive() : returns whether entity is alive or not 
 eName name() : returns name of entity 
 Animation animation()  : returns the animation corresponding to that entity      
void setAngle( float angle) : sets angle of entity
void setAlive( bool alive) : sets whether entity is alive or not 
void setName( eName name) : sets the name of the entity 
void setAnimation( Animation & a) : sets animation of the entity
virtual void update() : calls the update function from animation class 
 void draw(sf::RenderWindow& app): sets position , rotation and sprite of each corresponding entity and draws accordingly
virtual ~Entity(): virtual destructor 


# Player class , derived from entity class
Functions:
Player(Animation & a, float x, float y, float angle = 0.f, float radius=1.f):  initializes values
 bool thrust() : checks for thrust
 void setThrust( bool thrust) : sets thrust
 int lives()  : returns lives
 void setLives( int lives) : sets lives
 void reset(Animation & a, float x, float y, float angle): resetsplayer        
 void update(): updates animation ,updates x and y positions of the player , resets player position when beyond the width and height of the window.
# Asteroid class, derived from entity class 
Functions:
 Asteroid( Animation & a, float x, float y, float angle = 0.f, float radius = 1.f): constructor initializes values.
 void update(): updates animation , x and y positions of the asteroid , resets asteroid position when beyond the width and height of the window.


# Bullet class, derived from entity class 
Functions:
Bullet( Animation & a, float x, float y, float angle = 0.f, float radius = 1.f):  constructor , initializes values.
  void update(): updates x and y positions of the bullet and sets bullet life to false if bullet moves outside the window.

# Outputs
# Menu
<img width="415" alt="menu" src="https://github.com/bivek-shrestha/StarWars/assets/155466197/b634bc4a-d507-4ded-9e4f-c927ce11dacc">



# Options

<img width="412" alt="options" src="https://github.com/bivek-shrestha/StarWars/assets/155466197/073e1e76-b965-4571-95bc-1e4456187d07">

# Game Play

<img width="415" alt="gameplay" src="https://github.com/bivek-shrestha/StarWars/assets/155466197/985d7fc5-0a35-487c-b8df-061db1b2158c">

# GameOver

<img width="406" alt="gameover" src="https://github.com/bivek-shrestha/StarWars/assets/155466197/bc16b554-f1de-48f8-8d0b-9bca1ac3c5b3">

# References
Robert Lafore,  “Object Oriented Programming with C++”, Sams Publication.
Daya Sagar Baral and Diwakar Baral, “The Secrets of Object Oriented Programming”, Bhundipuran Prakasan.
SFML Game Development -Artur Moreira, Henrik Vogelius Hansson, and Jan Haller.
Programming principles and Practice using C++- Bjarne Stroustrup.
Beginning C++ Game Programming - John Horton.
https://www.sfml-dev.org/tutorials/2.5/
https://opengameart.org/
https://www.videvo.net/
