#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <fstream>
#include <istream>
#include "GameMap.h"
#include "Button.h"
#include "Player.h"
#include "User.h"
#include "Computer.h"
#include "ToolBar.h"
#include "GameObjects.h"
#include <vector>
#include "Score.h"


constexpr auto BOARD_SIZE = 600;
enum XYZwinner{USERWON, COMPUTERWON, TIE};

class Controller
{
public:

	Controller();
	void newGame(bool exsist); //will make a new game, using for restart too.
	void run(); //the main run function of the game.
	void eventhandler(); //eventhandler func is for the sf events.
	int colorToInt(sf::Color color); //get a color code.
	void buttonActionToolBar(size_t i); //buttons handler
	void clickAction(); //click handler
	void gameOver(XYZwinner x); //if the game is over, will come here.

	~Controller();

private:
	GameMap m_map; //GameMap member for create the map and use hes methods.
	sf::Vector2i mouse_pos; //mouse position.
	sf::Vector2f translated_pos;
	sf::RenderWindow m_window; //the window
	ToolBar m_myToolBar;
	std::vector<std::unique_ptr<Player>>m_players; //players vector
	std::unique_ptr<Score> m_scores; //players scores member (class Score)
	sf::Event event; //event
	bool m_playing; //false just when the game is over.

	//winnerScreenHandles
	sf::Text m_text;
	sf::Font m_font;

};

