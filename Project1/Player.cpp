#include "Player.h"

/*--------------------------Constructor------------------------*/
Player::Player(GameObjects * x)
	:y(x)
{
	newPlayer();
}
/*--------------------------New Player create------------------------*/
void Player::newPlayer()
{
	m_holdByMe.clear();
	m_holdByMe.push_back(y);
	m_usrColor = y->get_color();
	m_usrPosition = y->getPosition();
}
/*--------------------------to get user starts color------------------------*/
sf::Color Player::getUsrColor()
{
	return m_usrColor;
}
/*--------------------------set user starts color------------------------*/
void Player::setUsrColor(sf::Color color)
{
	m_usrColor = color;
}
/*--------------------------get user start position------------------------*/
sf::Vector2f Player::getUsrStartPos()
{
	return m_usrPosition;
}
/*--------------------------set new shape holds------------------------*/
void Player::setNewHolds(GameObjects * x)
{
	m_holdByMe.push_back(x);
}
/*--------------------------get holdByMe vec size------------------------*/
size_t Player::holdsVecSize()
{
	return m_holdByMe.size();
}
/*--------------------------get shapes from holds by index------------------------*/
GameObjects & Player::getHolds(size_t i)
{
	return *m_holdByMe[i];
}
/*--------------------------conquer!------------------------*/
void Player::conquer(sf::Color choosed_color)
{
	for (size_t i = 0; i < m_holdByMe.size(); i++)
	{
		m_holdByMe[i]->conquer_neighbors(choosed_color, m_holdByMe);
	}
}
/*--------------------------nei color function------------------------*/
void Player::neiCoColors()
{
	for (size_t i = 0; i < 2; i++)
	{
		if (m_holdByMe.size() > 0)
			while (m_holdByMe[0]->get_color() == m_holdByMe[0]->get_neighbor(i).get_color())
			{
				m_holdByMe[0]->get_neighbor(i).set_color(true, 0);
			}
	}
}
/*--------------------------get Player Score------------------------*/
float Player::getPlayerScore()
{
	my_Score = 0;
	for(auto & k: m_holdByMe)
	{
		my_Score += k->getShapeScore();
	}
	return my_Score;
}
/*--------------------------destructor------------------------*/
Player::~Player()
{
}