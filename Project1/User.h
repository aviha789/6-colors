#pragma once
#include "Player.h"
class User :
	public Player
{
public:
	User(GameObjects * x);
	int GridiComputerAlgorithm(sf::Color me, sf::Color him) { return 0; }//not used here.

	
	~User();
};

