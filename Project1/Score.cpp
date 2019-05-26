#include "Score.h"


/*--------------------------Constructor------------------------*/
Score::Score(std::vector<std::unique_ptr<Player>>& players)
	:m_players(players)
{
	m_font.loadFromFile("Font/CRACKERSBRUSHER.otf");
	mytexts.resize(4);
	updateScore();
	//creating the MyScores vector
	for (size_t i = 0; i < 2; i++)
	{
		MyScores.push_back(sf::RectangleShape({ 75, 20 }));
		MyScores[i].setFillColor(sf::Color::Cyan);
		MyScores[i].setOutlineColor(sf::Color::Black);
		MyScores[i].setOutlineThickness(2);
		MyScores[i].setPosition(sf::Vector2f(125 + (i*285), 650));
	}
	//creating the texts vector
	for (size_t i = 0; i < mytexts.size(); i++)
	{
		if(i<2)
			mytexts[i].setPosition(MyScores[i].getPosition() - sf::Vector2f(-5, 5));
		else
			mytexts[i].setPosition(MyScores[i-2].getPosition() - sf::Vector2f(90+((i-2)*45), 5));

		mytexts[i].setFont(m_font);
		mytexts[i].setFillColor(sf::Color::Black);
		mytexts[i].setCharacterSize(20);
	}
}
/*--------------------------Update scores of players------------------------*/
void Score::updateScore()
{

	mytexts[PLAYER].setString(std::to_string(m_players[PLAYER]->getPlayerScore()));
	mytexts[COMPUTER].setString(std::to_string(m_players[COMPUTER]->getPlayerScore()));
	mytexts[PLAYER + 2].setString("Your Score:");
	mytexts[COMPUTER + 2].setString("Opponent Score:");
}
/*--------------------------Draw function------------------------*/
void Score::draw(sf::RenderWindow & window)
{
	for (size_t i = 0; i < mytexts.size(); i++)
	{
		if(i<2)
			window.draw(MyScores[i]);
		window.draw(mytexts[i]);
	}
}
/*--------------------------destructor------------------------*/
Score::~Score()
{
}
