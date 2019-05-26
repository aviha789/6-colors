#pragma once
#include "GameObjects.h"

class Square :
	public GameObjects
{
public:
	Square(const sf::Vector2f& pos, bool random, int num);
	float getShapeScore();
	~Square();
};

