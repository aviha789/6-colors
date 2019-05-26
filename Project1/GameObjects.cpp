#include "GameObjects.h"


/*--------------------------Constructor------------------------*/
GameObjects::GameObjects():
	conqered(false)
{
}

/*--------------------------set Color Function on shape------------------------*/
void GameObjects::set_color(bool random, int num)
{
	int color = num;
	if (random)
		color = rand() % 6;

	switch (color)
	{
	case 0:
		m_color = sf::Color::Blue;
		break;
	case 1:
		m_color = sf::Color::Red;
		break;
	case 2:
		m_color = sf::Color::Green;
		break;
	case 3:
		m_color = sf::Color::Black;
		break;
	case 4:
		m_color = sf::Color::Magenta;
		break;
	case 5:
		m_color = sf::Color::Yellow;
		break;
	}
	m_shape.setFillColor(m_color);
}
/*--------------------------Draw------------------------*/
void GameObjects::draw(sf::RenderWindow & window)
{
	window.draw(m_shape);
}
/*--------------------------get Color------------------------*/
sf::Color GameObjects::get_color()
{
	return m_color;
}
/*--------------------------get Position------------------------*/
sf::Vector2f GameObjects::getPosition()
{
	return m_position;
}
/*--------------------------get Shape------------------------*/
sf::ConvexShape *GameObjects::get_shape()
{
	return &m_shape;
}
/*--------------------------add Neighbor------------------------*/
void GameObjects::add_neighbor(GameObjects &obj)
{
	m_neighbors.push_back(&obj);
}
/*--------------------------Neighbor function------------------------*/
bool GameObjects::neighbor(GameObjects & obj)
{
	auto border = m_shape.getGlobalBounds();
	auto objborder = obj.m_shape.getGlobalBounds();
	border.height -= 9;
	border.width -= 9;
	objborder.height -= 9;
	objborder.width -= 9;
	return border.intersects(objborder);
}

/*--------------------------get Neighbor------------------------*/
GameObjects & GameObjects::get_neighbor(int i)
{
	return *m_neighbors[i];
}
/*--------------------------get Neighbor Vector Size------------------------*/
size_t GameObjects::getNeighborVecSize()
{
	return m_neighbors.size();
}
/*--------------------------Handle Recursively conquers neighbors------------------------*/
void GameObjects::conquer_neighbors(sf::Color choosed_color, std::vector<GameObjects*>& holdbyme)
{

	set_color(false, colorToInt(choosed_color) );
	conqered = true;
	m_shape.setOutlineColor(sf::Color::White);
	for (size_t i = 0; i < m_neighbors.size(); i++)
	{
		if (m_neighbors[i]->get_color() == choosed_color && !m_neighbors[i]->conqered)
		{
			m_neighbors[i]->conquer_neighbors(choosed_color, holdbyme);
			holdbyme.push_back(m_neighbors[i]);
		}
	}
}
/*--------------------------color to int function------------------------*/
int GameObjects::colorToInt(sf::Color color)
{

	if (color == sf::Color::Blue)
		return 0;
	else if (color == sf::Color::Red)
		return 1;
	else if (color == sf::Color::Green)
		return 2;
	else if (color == sf::Color::Black)
		return 3;
	else if (color == sf::Color::Magenta)
		return 4;
	else if (color == sf::Color::Yellow)
		return 5;
	
	else 
		return 6;
}
/*--------------------------Int to color function!------------------------*/
//send a color code and get the color.
sf::Color GameObjects::intToColor(int x)
{
	sf::Color value;
	switch (x)
	{
	case 0:
		value = sf::Color::Blue;
		break;
	case 1:
		value = sf::Color::Red;
		break;
	case 2:
		value = sf::Color::Green;
		break;
	case 3:
		value = sf::Color::Black;
		break;
	case 4:
		value = sf::Color::Magenta;
		break;
	case 5:
		value = sf::Color::Yellow;
		break;
	}
	return value;
}
/*--------------------------get If Conquered function------------------------*/
bool GameObjects::getIfConquered()
{
	return conqered;
}
/*--------------------------set If Conquered function------------------------*/
void GameObjects::setIfConquered(bool x)
{
	conqered = x;
}
/*--------------------------Calculate the scores function!------------------------*/
/*This function will calculate what is the percentage of triangle and of square.
at the end it will make sure the board is 100% and 2 triangles means one Square.*/
void GameObjects::calculateScoresByPercent(int squaresNum, int triNum)
{
	shapesCount.resize(2);
	shapesCount[SQUARES] = (float)squaresNum*2;
	shapesCount[TRIANGLES] = (float)triNum;
	totalShapesScore = shapesCount[SQUARES] + (shapesCount[TRIANGLES]);
	triScore = (1 / (totalShapesScore ))*100;
	squareScore = (2 / (totalShapesScore))*100;
}

/*--------------------------destructor------------------------*/
GameObjects::~GameObjects()
{
}


