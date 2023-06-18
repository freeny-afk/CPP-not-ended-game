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


//Initialization of window and enemies
void GMWindow::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->GameWindow = new sf::RenderWindow(this->videoMode, "ABC", sf::Style::Default);
	this->GameWindow->setTitle("Albuquerque");
}

void GMWindow::initEnemies()
{
	this->enemy.setSize(sf::Vector2f(50,50));
	this->enemy.setFillColor(sf::Color::Blue);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->wKey = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->wKey = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->wKey = 3;
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
	bckTexture.loadFromFile("background.png");
	bckSprite.setTexture(bckTexture);
	bckSprite.setPosition(270, 230);
}

void GMWindow::bckMove() {
	switch (this->wKey) {
	case(1):
		bckSprite.move(0.2, 0);
		break;
	case(2):
		bckSprite.move(-0.2, 0);
		break;
	case(3):
		bckSprite.move(0, 0.2);
		break;
	case(4):
		bckSprite.move(0, -0.2);
		break;
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
		heroSprite.setPosition(270, 230);
		heroSprite.setTextureRect(sf::IntRect(10, 20, 40, 42));
		heroSprite.setScale(2, 2);

		this->currentFrame += 8 * time;
		if (this->currentFrame > 6) this->currentFrame -= 6;
		heroSprite.setTextureRect(sf::IntRect(10 + 64 * int(this->currentFrame), 20, 40, 45));
		gameTime();
		break;
	case(2):
		heroTexture.loadFromFile("texture_run_right.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setPosition(270, 230);
		heroSprite.setTextureRect(sf::IntRect(10, 20, 40, 42));
		heroSprite.setScale(2, 2);

		this->currentFrame += 8 * time;
		if (this->currentFrame > 6) this->currentFrame -= 6;
		heroSprite.setTextureRect(sf::IntRect(10 + 64 * int(this->currentFrame), 20, 40, 45));
		gameTime();
		break;
	case(3):
		heroTexture.loadFromFile("texture_stay.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		heroSprite.setPosition(280, 250);
		heroSprite.setScale(2, 2);
		break;
	case(4):
		heroTexture.loadFromFile("texture_stay.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		heroSprite.setPosition(280, 250);
		heroSprite.setScale(2, 2);
		break;
	case(0):
		heroTexture.loadFromFile("texture_stay.png");
		heroSprite.setTexture(heroTexture);
		heroSprite.setTextureRect(sf::IntRect(0, 0, 32, 33));
		heroSprite.setPosition(280, 250);
		heroSprite.setScale(2, 2);
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
	this->bckMove();
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
	this->GameWindow->draw(bckSprite);
	this->GameWindow->draw(heroSprite);

	this->GameWindow->display();
}
