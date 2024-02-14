# StarWars
Asteroid game made using C++

# Installation Guide
# Install C++ into your system
To install a C++ compiler on your system using the terminal, you'll need to use a package manager that is appropriate for your operating system. Below are instructions for different operating systems: <br>

1. Linux (Debian/Ubuntu): <br>

sudo apt update
sudo apt install g++ <br>
This will install the GNU Compiler Collection (g++). <br>

2. Linux (Fedora/RHEL): <br>

sudo dnf install gcc-c++ <br>
For RHEL or CentOS, you might need to enable the EPEL repository first. <br>

3. macOS: <br>
On macOS, you can use Homebrew to install GCC: <br>


brew install gcc <br>
This will install the GNU Compiler Collection, and you can use g++ for C++ compilation. <br>

4. Windows: <br>
If you are using Windows, you can install the Windows Subsystem for Linux (WSL) and then follow the Linux instructions. Alternatively, you can use a Windows compiler such as MinGW or Visual Studio. <br>

- MinGW: <br>
Download and install MinGW from MinGW website. <br>
During installation, select the C++ compiler option. <br>
Add the MinGW bin directory to your system's PATH environment variable <br>.
- Visual Studio: <br>
Install Visual Studio Community edition from Visual Studio website. <br>
During installation, make sure to select the "Desktop development with C++" workload. <br>
Verifying the Installation: <br>
After the installation is complete, you can verify that the C++ compiler is installed by opening a terminal and typing: <br>


g++ --version

# Introduction 
The player is represented by a spaceship on the screen. The player controls the ship by using the left and right arrow keys to move left and right and the up arrow key to move upwards. There are no brakes and to slow down so the player must apply the thrusters to counteract the existing velocity. The spaceship also fires bullets to destroy the asteroid in its path through the spacebar key. 

# Classes and Fuctions used
# Main file:
 main.cpp: creates an object of Game class i.e game and calls game.run() <br>
Game Class: <br>
Functions: <br>
Game(int width , int height): Game class constructor which takes in the window width and height as parameters. <br>
void initialize(): initializes textures, asteroids , player, score and lives. <br>
void reset(): resets the player , score , lives and asteroids. <br>
bool isCollide(Entity *a, Entity *b) : checks for collision between entities. <br>
void handleEvents(): checks for keyboard inputs, allows switching between different options on the main menu, creates bullets on spacebar, rotates the player on left and right arrow keys and sets thrust to true on up arrow key. <br>
void handleCollisions(): checks for collision between entities and create explosion at collision site, updates score , lives of player , and resets player to original position when a life is lost <br>
void update(): ends the explosion , creates new asteroids and calls the update function of every entity <br>
void draw(): draws the background, the entities , score, lives, and gameover text onto the screen <br>
Void run(): initializes, handles events, handles collisions , updates and then draws all while the window is open. <br>


# Menu class:
Functions: <br>
Menu(): sets the background, the fonts and text representing the choices to be displayed on the menu. <br>
 void MoveUp(): sets a different color to the selected choice while upward movement <br>
 void MoveDown(): sets a different color to the selected choice while downward movement <br>
void draw(sf::RenderWindow& window): draws background , title and menu choices onto the window. <br>
 int GetPressedItem(): returns selected choice’s index. <br>
# Entity class 
Functions: <br>
Entity( Animation & a, float x, float y, float angle = 0.f, float radius= 1.f) : initializes values. <br>
 float x() : returns x position of entity  <br>
 float y()  : returns y position of entity <br>
float radius() : returns radius of entity <br>
 float angle() : returns angle at which the entity is placed <br>
 bool isAlive() : returns whether entity is alive or not  <br>
 eName name() : returns name of entity  <br>
 Animation animation()  : returns the animation corresponding to that entity     <br> 
void setAngle( float angle) : sets angle of entity <br>
void setAlive( bool alive) : sets whether entity is alive or not <br>
void setName( eName name) : sets the name of the entity  <br>
void setAnimation( Animation & a) : sets animation of the entity <br>
virtual void update() : calls the update function from animation class  <br>
 void draw(sf::RenderWindow& app): sets position , rotation and sprite of each corresponding entity and draws accordingly <br>
virtual ~Entity(): virtual destructor <br>


# Player class , derived from entity class
Functions: <br>
Player(Animation & a, float x, float y, float angle = 0.f, float radius=1.f):  initializes values <br>
 bool thrust() : checks for thrust <br>
 void setThrust( bool thrust) : sets thrust <br>
 int lives()  : returns lives <br>
 void setLives( int lives) : sets lives <br>
 void reset(Animation & a, float x, float y, float angle): resetsplayer    <br>     
 void update(): updates animation ,updates x and y positions of the player , resets player position when beyond the width and height of the window. <br>
# Asteroid class, derived from entity class 
Functions: <br>
 Asteroid( Animation & a, float x, float y, float angle = 0.f, float radius = 1.f): constructor initializes values. <br>
 void update(): updates animation , x and y positions of the asteroid , resets asteroid position when beyond the width and height of the window. 


# Bullet class, derived from entity class 
Functions: <br>
Bullet( Animation & a, float x, float y, float angle = 0.f, float radius = 1.f):  constructor , initializes values. <br>
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
Robert Lafore,  “Object Oriented Programming with C++”, Sams Publication. <br>
Daya Sagar Baral and Diwakar Baral, “The Secrets of Object Oriented Programming”, Bhundipuran Prakasan. <br>
SFML Game Development -Artur Moreira, Henrik Vogelius Hansson, and Jan Haller. <br>
Programming principles and Practice using C++- Bjarne Stroustrup. <br>
Beginning C++ Game Programming - John Horton. <br>
https://www.sfml-dev.org/tutorials/2.5/ <br>
https://opengameart.org/ <br>
https://www.videvo.net/ <br>
