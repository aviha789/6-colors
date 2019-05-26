#include "Computer.h"



/*--------------------------Constructor------------------------*/
Computer::Computer(GameObjects * x) :
	Player(x)
{
}




/*--------------------------Gridi Algorithm Func------------------------*/
int Computer::GridiComputerAlgorithm(sf::Color me, sf::Color him)
{
	GameObjects p; //creating a local GameObjects member to use the class.
	std::vector<int> colors = colorsFrequency(&p); //calls the frequency function
												   //to get the colors counters
	int max = 0, index = 0; //max will hold the current max color count. index will
							//be returned as color code.
	for (size_t i = 0; i < colors.size(); i++)
	{
		if (i == p.colorToInt(me) || i == p.colorToInt(him)) //if the color is used,
			colors[i] = -1;									//we will force him not chose it.

		if (colors[i] > max) //the condition
		{
			max = colors[i];
			index = (int)i;
		}
	}
	return index;
}
/*--------------------------Color Frequency Function As Detailed------------------------*/
std::vector<int> Computer::colorsFrequency(GameObjects* p)
{
	std::vector<int> colors;
	colors.resize(6);

	for (size_t i = 0; i < m_holdByMe.size(); i++)
	{
		for (size_t j = 0; j < m_holdByMe[i]->getNeighborVecSize(); j++)
		{
			if (!m_holdByMe[i]->get_neighbor(j).getIfConquered())
				switch (p->colorToInt(m_holdByMe[i]->get_neighbor(j).get_color()))
				{
				case 0:
					colors[0] += 1;
					break;
				case 1:
					colors[1] += 1;
					break;
				case 2:
					colors[2] += 1;
					break;
				case 3:
					colors[3] += 1;
					break;
				case 4:
					colors[4] += 1;
					break;
				case 5:
					colors[5] += 1;
					break;
				}
		}
	}
	return colors;
}
/*--------------------------destructor------------------------*/
Computer::~Computer()
{
}
