#pragma once
#include "Window.h"
int main() {
	GMWindow GameWindow;
	GameWindow.initHero();
	//Game loop
	GameWindow.setLocation();
	GameWindow.initBck();
	while (GameWindow.isRunning()) 
	{

		//Window update
		GameWindow.update();
		//Window render
		GameWindow.render();

	}

	GameWindow.initBck();
	return 0;
}