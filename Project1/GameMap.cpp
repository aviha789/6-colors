#include "GameMap.h"
#include "GameObjects.h"
#include "Triangle.h"
#include <iostream>


/*--------------------------Constructor------------------------*/
GameMap::GameMap()
{

	m_map.setSize(sf::Vector2f(540.f, 540.f));
	m_map.setPosition(sf::Vector2f(30.f, 30.f));
	m_map.setFillColor(sf::Color::White);
	starter();
	check_neighbors();
	//newMap();

}
/*--------------------------For New Game!------------------------*/
void GameMap::newMap()
{
	for (size_t i = 0; i < m_shapes.size(); i++)
	{
		m_shapes[i]->set_color(true, 0);
		m_shapes[i]->setIfConquered(false);
		m_shapes[i]->get_shape()->setOutlineColor(sf::Color::Black);
	}
}
/*--------------------------Draw function------------------------*/
void GameMap::draw(sf::RenderWindow & window)
{
	window.draw(m_map);
}
/*--------------------------Draw Objects------------------------*/
void GameMap::drawobjects(sf::RenderWindow & window)
{
	for (int i = 0; i < m_shapes.size(); i++)
	{
		m_shapes[i]->draw(window);
	}
	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i]->draw(window);
	}

}
/*--------------------------Creating the map and the shapes------------------------*/
void GameMap::starter()
{
	int squareNum = 0, triNum = 0;
	for (size_t i = 0; i < 26; i++)
		for (size_t j = 0; j < 27; j++)
		{
			m_shapes.push_back(std::make_unique<Square>(sf::Vector2f(20.f*(i + 1.5), 20.f*(j + 1)), true, 0));
			++squareNum;
		}

	for (size_t i = 0; i < 27; i++)
		for (size_t j = 0; j < 26; j++)
		{
			m_shapes.push_back(std::make_unique<Square>(sf::Vector2f(20.f*(i + 1), 20.f*(j + 1.5)), true, 0));
			++squareNum;
		}
	
	for (int i = 0; i < 28; i++)
		for (int j = 0; j < 27; j++)
		{
			if (i == 0)
			{
				m_shapes.push_back(std::make_unique<Triangle>(sf::Vector2f(20.f*(j + 2.5), 20.f*(i + 1)), 90, true, 0));
				++triNum;
			}
			//top line
			if (i == 26)
			{
				m_shapes.push_back(std::make_unique<Triangle>(sf::Vector2f(20.f*(j + 1.5), 20.f*(i + 3)), 270, true, 0));
				++triNum;
			}
			//lower line
			if (j == 0 && i != 0)
			{
				m_shapes.push_back(std::make_unique<Triangle>(sf::Vector2f(20.f*(j + 1), 20.f*(i + 0.5)), 0, true, 0));
				++triNum;
			}
			//left line
			if (j == 26 && i != 27)
			{
				m_shapes.push_back(std::make_unique<Triangle>(sf::Vector2f(20.f*(j + 3), 20.f*(i + 2.5)), 180, true, 0));
				++triNum;
			}
			//right line
		}
	
	for (int i = 0; i < 6; i++)
	{
		m_buttons.push_back(std::make_unique<Button>(sf::Vector2f( ( (i + 1) * 80), (600) ), false , i));
	}
	for(auto & k: m_shapes)
		k->calculateScoresByPercent(squareNum, triNum);
}

/*--------------------------get buttons------------------------*/
sf::ConvexShape GameMap::get_button(int i)
{
	return *m_buttons[i]->get_shape();
}
/*--------------------------check neighbors func------------------------*/
void GameMap::check_neighbors()
{
	for (auto i =  m_shapes.cbegin() ; i != m_shapes.cend(); i++)
	{
		for (auto j = i+1 ; j != m_shapes.cend(); j++)
		{
			if((*i)->neighbor(*(*j)))
			{
				(*i)->add_neighbor(*(*j));
				(*j)->add_neighbor(*(*i));
			}
		}
	}
}
/*--------------------------get_shape func------------------------*/
GameObjects& GameMap::get_shape(int i)
{
	return *m_shapes[i];
}
/*--------------------------get the size of m_shape------------------------*/
size_t GameMap::getVectorSize()
{
	return m_shapes.size();
}
/*--------------------------destructor------------------------*/
GameMap::~GameMap()
{
}