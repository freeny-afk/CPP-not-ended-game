#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> //i do not fucking understand
#include <SFML/Audio.hpp> //why tf should I add dis libs cause
#include <SFML/Network.hpp> //i've already made it

class GMWindow
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow *GameWindow;
	sf::Event ev;
	//Game objects
	sf::RectangleShape enemy;
	//Mouse position containing vector o' 2 ints
	sf::Vector2i mousePos;
	// Declare and load a texture
	sf::Texture heroTexture;
	// Create a sprite
	sf::Sprite heroSprite;
	//What key is it
	int wKey;
	// Create a sprite
	sf::Sprite bckSprite;
	// Declare and load a texture
	sf::Texture bckTexture;
	// Derlaring clock
	sf::Clock clock;
	float currentFrame = 0;
	float time;
public:
	GMWindow();
	void gameTime();
	void whatKey();
	void initEnemies();
	void initWindow();
	void initHero();
	void initBck();
	void bckMove();
	void heroMove();
	bool isRunning();
	void updateEv();
	void updateMousePos();
	void update();
	void heroCh();
	void render();
	~GMWindow();
};

