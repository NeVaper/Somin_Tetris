#include <SFML/Graphics.hpp>
#include "Screens.h"
#include "Settings.h"

#include <fstream>
#include <iostream>

int main()
{
	//Applications variables
	std::vector<Screen*> screens;
	GameScreen screen = GameScreen::MENU;

	//Window creation
	sf::RenderWindow mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		"Somin Tetris: best clone ever!", sf::Style::Titlebar | sf::Style::Close);
	
	mainWindow.setFramerateLimit(FRAMERATE);

	//Screens preparations
	MenuScreen s;
	screens.push_back(&s);

	//Main loop
	//while (screen != GameScreen::EXIT)
	//{
	//	screen = screens[GameScreen::MENU]->run(mainWindow);
	//}

	auto test = Settings::getPlayMode();

	return EXIT_SUCCESS;
}