#include "Controller.h"

const int PLAYER_OBJECT = 1482;
const int PC_OBJECT = 1430;


/*--------------------------Constructor------------------------*/
Controller::Controller():
	m_window(sf::VideoMode(BOARD_SIZE, BOARD_SIZE+100), "Colors", sf::Style::Close)
{
	m_font.loadFromFile("Font/CRACKERSBRUSHER.otf");
	m_text.setFont(m_font);

	//creating the players.
	m_players.resize(2);
	m_players[PLAYER] = std::make_unique<User>(&m_map.get_shape(PLAYER_OBJECT));
	m_players[COMPUTER] = std::make_unique<Computer>(&m_map.get_shape(PC_OBJECT));
	//creating the Scores for the players.
	m_scores = std::make_unique<Score>(m_players);

	newGame(false); //newGame. false when we first start. true when we restarting
}
/*--------------------------New Game Function------------------------*/
void Controller::newGame(bool exsist)
{
	m_playing = true; //new game - so we playing! thats true.
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(20);

	if (exsist) //this condition for restart. if the game exsist
	{			//dont start over build it.
		m_map.newMap();
		m_players[PLAYER]->newPlayer();
		m_players[COMPUTER]->newPlayer();

	}
	//getting the first places.
	if (m_players[PLAYER]->getUsrColor() == m_players[COMPUTER]->getUsrColor())
		m_players[PLAYER]->getHolds(0).set_color(false, colorToInt(m_players[PLAYER]->getHolds(0).get_color()) + 1 ?6: -2);

	for (size_t i = 0; i < 2; i++)
	{
		m_players[i]->neiCoColors(); //checking the colors with nei
	}
}
/*--------------------------Run Function------------------------*/
void Controller::run()
{

	while (m_window.isOpen()) //as long as the window is open
	{
		m_window.clear(sf::Color(0, 255, 191));
		
		if (m_playing)
			m_map.drawobjects(m_window);

		m_window.draw(m_text); //draw different texts. (turns, who won...)
		m_myToolBar.draw(m_window); //the toolBar (exit, restart...)
		m_scores->updateScore(); //for update the scores before draw em!
		m_scores->draw(m_window); //now... draw em.
		m_window.display();
		eventhandler(); 
	}
}
/*--------------------------Event Handler function------------------------*/
void Controller::eventhandler()
{

	if (m_window.waitEvent(event))
	{


		if (m_playing) //if we playing, the text will use for turns.
		{				//and we checking if there is a winner.
			m_text.setPosition(sf::Vector2f(125, 670));
			m_text.setString("Your Turn!");

			if (m_players[PLAYER]->getPlayerScore() > 50)
				gameOver(USERWON);
			else if (m_players[COMPUTER]->getPlayerScore() > 50)
				gameOver(COMPUTERWON);
			else if (m_players[PLAYER]->getPlayerScore() == 50 && m_players[COMPUTER]->getPlayerScore() == 50)
				gameOver(TIE);
		}

		switch (event.type)
		{
		case sf::Event::Closed:
				m_window.close();
				break;
		case sf::Event::MouseButtonPressed:
			mouse_pos = sf::Mouse::getPosition(m_window);
			translated_pos = m_window.mapPixelToCoords(mouse_pos);
			
			clickAction();
			break;

		}
	}
}
/*--------------------------Color to int Function------------------------*/
int Controller::colorToInt(sf::Color color)
{

	if (color == sf::Color::Blue)
		return 0;
	else if (color == sf::Color::Red)
		return 1;
	else if (color == sf::Color::Green)
		return 2;
	else if (color == sf::Color::Black)
		return 3;
	else if (color == sf::Color::Magenta)
		return 4;
	else if (color == sf::Color::Yellow)
		return 5;
	else
		return 6;
}
/*--------------------------Buttons Action ToolBar Function------------------------*/
void Controller::buttonActionToolBar(size_t i)
{
	switch (i)
	{
	case 0:
		newGame(true);
		break;
	case 1:
		m_window.close();
		break;
	default:
		break;
	}

}
/*--------------------------Click Action Function------------------------*/
void Controller::clickAction()
{
	for (int i = 0; i < 6; i++)
	{
		if (m_map.get_button(i).getGlobalBounds().contains(translated_pos))
		{
			sf::Color color = m_map.get_button(i).getFillColor();

			if (m_players[PLAYER]->getHolds(0).get_color() == color || m_players[COMPUTER]->getHolds(0).get_color() == color)
				break;

			GameObjects p; //local member to use GameObjects methods.
			

			m_players[PLAYER]->conquer(color); //user move

			m_text.setPosition(sf::Vector2f(400, 670));
			m_text.setString("Opponent Turn...");

			m_players[COMPUTER]->conquer(p.intToColor(m_players[COMPUTER]->GridiComputerAlgorithm(
				m_players[PLAYER]->getHolds(0).get_color(), m_players[COMPUTER]->getHolds(0).get_color()))); //computer move

			break;
		}
	}
	for (size_t i = 0; i < m_myToolBar.getToolVecSize(); i++) //buttons Action loop.
	{
		if (m_myToolBar.getToolButton((int)i).getGlobalBounds().contains(translated_pos))
			buttonActionToolBar(i);
	}
}
/*--------------------------Game Over Function!------------------------*/
void Controller::gameOver(XYZwinner x)
{
	m_playing = false; //the game is over, so we are not playing.
	m_text.setPosition(sf::Vector2f(50, 300)); //we will use the text to
	m_text.setFillColor(sf::Color::Black);		//say who is the winner
	m_text.setCharacterSize(60);
	//cases to choose the right text!
	switch (x)
	{
	case USERWON:
		m_text.setString("You Are The Winner!");
		break;
	case COMPUTERWON:
		m_text.setString("You Have Lost! AGAIN?");
		break;
	case TIE:
		m_text.setString("Huh? BOTH OF YOU?!");
		break;
	default:
		break;
	}
}
/*--------------------------Destructor------------------------*/
Controller::~Controller()
{
}

