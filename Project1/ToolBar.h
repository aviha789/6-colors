#pragma once
#include "GameObjects.h"

class ToolBar
{
public:
	ToolBar();
	void draw(sf::RenderWindow & window);
	sf::RectangleShape getToolButton(size_t i); //get by index a button
	size_t getToolVecSize(); //get the toolbar vec size

	~ToolBar();

private:
	std::vector<sf::RectangleShape> MyToolBar;//the toolbar vector
	std::vector<sf::Text> mytexts; //our texts
	sf::Font m_font; //will hold the fint

};

