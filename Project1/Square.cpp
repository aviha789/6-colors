#include "Square.h"

/*--------------------------Square constructo-------------------------*/
//here where we create the squeres
Square::Square(const sf::Vector2f& pos, bool random, int num)
{
	m_position = pos;
	m_shape.setPointCount(4.f);
	m_shape.setPoint(0, sf::Vector2f(20, 11));
	m_shape.setPoint(1, sf::Vector2f(11, 20));
	m_shape.setPoint(2, sf::Vector2f(20, 29));
	m_shape.setPoint(3, sf::Vector2f(29, 20));

	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
	
	
	set_color(random, num);
	m_shape.setFillColor(get_color());
	m_shape.setPosition(pos);

	area = 1;
}
/*--------------------------return the score of this shape------------------------*/
float Square::getShapeScore()
{
	return squareScore;
}
/*--------------------------destructor------------------------*/
Square::~Square()
{
}
