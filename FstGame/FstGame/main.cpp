#pragma once
#include "Window.h"
int main() {
	GMWindow GameWindow;
	GameWindow.initHero();
	GameWindow.initBck();
	//Game loop
	while (GameWindow.isRunning()) 
	{
		GameWindow.initEnemies();
		//Window update
		GameWindow.update();
		//Window render
		GameWindow.render();
	}


	return 0;
}