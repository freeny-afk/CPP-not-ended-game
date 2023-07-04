#include "Window.h"

//Constructor and destructor
GMWindow::GMWindow()
{
	this->initWindow();
}

GMWindow::~GMWindow()
{
	delete this->GameWindow;
}





/// MAP INITING
/// /////////////////////////////////////////////////////////
/// </summary>
void GMWindow::setLocation()
{
	mapMap = {"11"};
}

void GMWindow::wtrBlock() 
{
	waterTexture.loadFromFile("water.png");
	waterSprite.setTexture(waterTexture);
	waterSprite.setTextureRect(sf::IntRect(0, 0, 128, 160));
	waterSprite.setPosition(280, 250);

	
	for (int i = 0; i < 0; i++)
		for (int j = 0; j < 0; j++)
			if (mapMap[i][j] == '1') { waterSprite.setPosition(280 + j * 128, 250 + i * 160); }
}
void GMWindow::rocksBack()
{
	rocksBackTexture.loadFromFile("rocksback.png");
	rocksBackSprite.setTexture(bckTexture);
	rocksBackSprite.setPosition(270, 230);
}
void GMWindow::rocksFront()
{
	rocksFrontTexture.loadFromFile("rocksfront.png");
	rocksFrontSprite.setTexture(bckTexture);
	rocksFrontSprite.setPosition(270, 230);
}
void GMWindow::tileCave()
{
	tileCaveTexture.loadFromFile("tileset.png");
	tileCaveSprite.setTexture(bckTexture);
	tileCaveSprite.setPosition(270, 230);
}
/////////////////////////////////////////////////////////////////////////////





//Initialization of window and enemies
void GMWindow::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->GameWindow = new sf::RenderWindow(this->videoMode, "ABC", sf::Style::Default);
	this->GameWindow->setTitle("Albuquerque");
}


bool GMWindow::isRunning()
{
	return this->GameWindow->isOpen();
}

void GMWindow::updateMousePos()
{
	this->mousePos = sf::Mouse::getPosition(*this->GameWindow);
}


void GMWindow::whatKey()
{
	this->wKey = 0;
	// Positioning object to the Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->wKey = 1;
	// Positioning object to the Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->wKey = 2;
	// Positioning object to the Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->wKey = 3;
	// Positioning object to the Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->wKey = 4;
}

void GMWindow::initHero()
{
	heroTexture.loadFromFile("texture_stay.png");
	heroSprite.setTexture(heroTexture);
	heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
	heroSprite.setScale(2, 2);
	heroSprite.setPosition(280, 250);

}

void GMWindow::initBck() 
{
	this->wtrBlock();
	// Draw it
	
	

	
}

void GMWindow::bckMove() {
	switch (this->wKey) {
	case(1):
	case(2):		
	case(3):		
	case(4):		
	case(0):
		break;
	}
}

void GMWindow::heroMove()
{
	switch (this->wKey) {
	case(1):
		heroTexture.loadFromFile("texture_run_left.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(10, 20, 40, 42));
		heroSprite.setScale(2, 2);
		this->currentFrame += 8 * time;
		if (this->currentFrame > 6) this->currentFrame -= 6;
		heroSprite.setTextureRect(sf::IntRect(10 + 64 * int(this->currentFrame), 20, 40, 45));
		gameTime();
		waterSprite.move(0.1, 0);
		heroSprite.move(-0.2, 0);
		break;
	case(2):
		heroTexture.loadFromFile("texture_run_right.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(10, 20, 40, 42));
		heroSprite.setScale(2, 2);
		this->currentFrame += 8 * time;
		if (this->currentFrame > 6) this->currentFrame -= 6;
		heroSprite.setTextureRect(sf::IntRect(10 + 64 * int(this->currentFrame), 20, 40, 45));
		gameTime();
		heroSprite.move(0.2, 0);
		break;
	case(3):
		heroTexture.loadFromFile("texture_stay.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		heroSprite.setScale(2, 2);
		this->currentFrame += 8 * time;
		if (this->currentFrame > 4) this->currentFrame -= 4;
		heroSprite.setTextureRect(sf::IntRect(0 + 32 * int(this->currentFrame), 0, 32, 33));
		gameTime();
		heroSprite.move(0, -0.2);
		break;
	case(4):
		heroTexture.loadFromFile("texture_stay.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		heroSprite.setScale(2, 2);
		heroSprite.move(0, 0.2);
		break;
	case(0):
		heroTexture.loadFromFile("texture_stay.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		heroSprite.setScale(2, 2);
		this->currentFrame += 4 * time;
		if (this->currentFrame > 9) this->currentFrame -= 9;
		if (this->currentFrame <= 2)
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		if (this->currentFrame > 2 and this->currentFrame <= 4)
		heroSprite.setTextureRect(sf::IntRect(0 + 32 * int((this->currentFrame)-2), 0, 32, 33));
		if (this->currentFrame > 4 and this->currentFrame <= 8)
		heroSprite.setTextureRect(sf::IntRect(96, 0, 32, 33));
		if (this->currentFrame > 8 and this->currentFrame <= 9)
		heroSprite.setTextureRect(sf::IntRect(32, 0, 32, 33));
		gameTime();
		break;
	}
}

void GMWindow::updateEv()
{
	while (this->GameWindow->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->GameWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->GameWindow->close();
			break;
		}		
	}
}

void GMWindow::gameTime() {
	this->time = clock.getElapsedTime().asSeconds();
	this->clock.restart();
	std::cout << this->time << "\n";
}

//Updating the frame
void GMWindow::update()
{
	//Updating frames
	this->updateEv();
	//Updating mouse position
	this->updateMousePos();
	//Asking what key is it
	this->whatKey();

	this->heroMove();
}

void GMWindow::render()
{
	/*
		-clears old frame
		-render new objects
		-display frame
	*/
	this->GameWindow->clear(sf::Color::Red);
	// Draw it
	
	this->GameWindow->draw(heroSprite);
	this->GameWindow->draw(waterSprite);
	this->GameWindow->display();
}
