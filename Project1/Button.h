#pragma once
#include "GameObjects.h"

class Button :
	public GameObjects
{
public:
	Button(const sf::Vector2f& pos, bool random, int num); //use for buttons in game.
	~Button();
	
};

