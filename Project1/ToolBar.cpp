#include "ToolBar.h"


/*--------------------------constructor------------------------*/
ToolBar::ToolBar()
{
	m_font.loadFromFile("Font/CRACKERSBRUSHER.otf");
	mytexts.resize(2);
	mytexts[0].setString("Restart");
	mytexts[1].setString("Exit");

	for (size_t i = 0; i < 2; i++)
	{
		MyToolBar.push_back(sf::RectangleShape({ 75, 20}));
		MyToolBar[i].setOutlineColor(sf::Color::Black);
		MyToolBar[i].setOutlineThickness(1);
		MyToolBar[i].setPosition(sf::Vector2f(175*(i+1), 5));
		mytexts[i].setPosition(MyToolBar[i].getPosition() - sf::Vector2f(-10, 5));
		mytexts[i].setFont(m_font);
		mytexts[i].setFillColor(sf::Color::White);
		mytexts[i].setOutlineColor(sf::Color::Black);
		mytexts[i].setOutlineThickness(1);
		mytexts[i].setCharacterSize(20);
	}
	MyToolBar[0].setFillColor(sf::Color::Green);
	MyToolBar[1].setFillColor(sf::Color::Red);


}
/*--------------------------draw function------------------------*/
void ToolBar::draw(sf::RenderWindow & window)
{
	for (size_t i = 0; i < MyToolBar.size(); i++)
	{
		window.draw(MyToolBar[i]);
		window.draw(mytexts[i]);
	}
}
/*--------------------------getToolButton func------------------------*/
sf::RectangleShape ToolBar::getToolButton(size_t i)
{
	return MyToolBar[i];
}

size_t ToolBar::getToolVecSize()
{
	return MyToolBar.size();
}

/*--------------------------destructor------------------------*/
ToolBar::~ToolBar()
{
}
