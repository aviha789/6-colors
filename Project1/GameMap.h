#pragma once
#include <vector>
#include "GameObjects.h"
#include <memory>
#include "Button.h"
#include "Square.h"

class GameMap
{
public:
	GameMap(); 
	void newMap();
	void draw(sf::RenderWindow & window); //for draw the map
	void drawobjects(sf::RenderWindow & window); //for draw the shapes
	void starter(); //will create here the objects.
	sf::ConvexShape get_button(int i); //get buttons of the gameplay
	void check_neighbors(); //check neighbors for each shape
	GameObjects &get_shape(int i); //get shape
	size_t getVectorSize(); //returnes m_shapes vector size
	~GameMap();

private:
	std::vector<std::unique_ptr<GameObjects>> m_shapes; //all shapes here
	sf::RectangleShape m_map; //the map itself!
	std::vector < std::unique_ptr<Button>> m_buttons; //all buttons here
};

