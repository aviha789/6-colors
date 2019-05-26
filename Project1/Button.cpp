#include "Button.h"


/*--------------------------Constructor------------------------*/
//this constructor will create the gameplay buttons, the once with colors.
Button::Button(const sf::Vector2f& pos, bool random, int num)
{
	m_position = pos;
	m_shape.setPointCount(4.f);
	m_shape.setPoint(0, sf::Vector2f(0, 0));
	m_shape.setPoint(1, sf::Vector2f(0, 40));
	m_shape.setPoint(2, sf::Vector2f(40, 40));
	m_shape.setPoint(3, sf::Vector2f(40, 0));

	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(1);
	set_color(random, num);
	m_shape.setFillColor(get_color());

	m_shape.setPosition(pos);
}

/*--------------------------destructor------------------------*/
Button::~Button()
{
}

