#pragma once
#include "Player.h"

class Computer :
	public Player
{
public:
	Computer(GameObjects * x);
	int GridiComputerAlgorithm(sf::Color me, sf::Color him); //Gridi Algorithm as we asked.
	std::vector<int> colorsFrequency(GameObjects* p); //this function getting the counters of
	~Computer();									  //the colors around, for the Gridi Algorithm.


};

