#pragma once
#include "Player.h"

enum whoPlay { PLAYER, COMPUTER };

class Score
{
public:
	Score(std::vector<std::unique_ptr<Player>>& m_players);
	void updateScore(); //update the scores of the players
	void draw(sf::RenderWindow & window); //draw function
	~Score();

private:
	sf::Font m_font;//for hold the font
	std::vector<sf::RectangleShape> MyScores; //places for the scores
	std::vector<std::unique_ptr<Player>>&m_players;	//for getting the scores
	std::vector<sf::Text> mytexts; //will hold the texts
};

