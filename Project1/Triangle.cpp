#include "Triangle.h"


/*--------------------------Triangle Constructor------------------------*/
//this is where we creating the triangles
Triangle::Triangle(const sf::Vector2f& pos, int rot, bool random, int num)
{
	m_position = pos;
	m_shape.setPointCount((size_t)3.f);
	m_shape.setPoint(0, sf::Vector2f(10, 1));
	m_shape.setPoint(1, sf::Vector2f(10, 19));
	m_shape.setPoint(2, sf::Vector2f(19, 10));
	

	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
	m_shape.setPosition(pos);
	m_shape.rotate((float)rot);

	set_color(random, num);

	m_shape.setFillColor(get_color());

	area = 0.5;
}
/*--------------------------get the shape score------------------------*/
float Triangle::getShapeScore()
{
	return triScore;
}
/*--------------------------destructor------------------------*/
Triangle::~Triangle()
{
}
