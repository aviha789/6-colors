#pragma once
#include "GameObjects.h"
class Triangle :
	public GameObjects
{
public:
	Triangle(const sf::Vector2f& pos, int rot, bool random, int num);
	float getShapeScore();
	~Triangle();
};

