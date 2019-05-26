#pragma once
#include "GameObjects.h"

class Player
{
public:
	Player(GameObjects* x);
	void newPlayer(); //new player make

	sf::Color getUsrColor(); //get the player color
	void setUsrColor(sf::Color color); //set the player color
	sf::Vector2f getUsrStartPos(); //get the start position.
	void setNewHolds(GameObjects* x); //set new Holds into HoldByMe vec
	size_t holdsVecSize(); //return its size
	GameObjects& getHolds(size_t i); //get the holds of this player by index
	void conquer(sf::Color choosed_color); //action function to conquer more areas
	void neiCoColors(); //nei CoColors
	virtual int GridiComputerAlgorithm(sf::Color me, sf::Color him)=0; //Pure Virtual Func for gridi algorithm.
	float getPlayerScore(); //get the player score.
	~Player();

	
	
protected:
	float my_Score = 0; //score member
	GameObjects* y; //gameObjects member to hold the start shape
	std::vector<GameObjects*> m_holdByMe; //holds by this player vector
	sf::Color m_usrColor; //user color
	sf::Vector2f m_usrPosition; //user start position
	
};


