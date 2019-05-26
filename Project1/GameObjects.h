#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum ObjectColors {Blue,Red,Green,White,Magenta,Yellow};
enum shapesArr {TRIANGLES, SQUARES};

class GameObjects
{
public:
	GameObjects();
	~GameObjects();
	void set_color(bool random, int num); //to set color on an object.
	void draw(sf::RenderWindow & window); //draw function
	sf::Color get_color(); //get an object color
	sf::Vector2f getPosition(); //get an object position
	sf::ConvexShape *get_shape(); //get a pointer to a shape.
	void add_neighbor(GameObjects &obj); //insert neighbor to the vector
	bool neighbor(GameObjects &obj); //ask if he is a neighbor
	GameObjects& get_neighbor(int i); //get neighbor from the vec
	size_t getNeighborVecSize(); //return the vector size
	void conquer_neighbors(sf::Color choosed_color, std::vector<GameObjects*>& holdbyme); //conquer function.
	int colorToInt(sf::Color color); //color to code.
	sf::Color intToColor(int x);//code to color
	bool getIfConquered(); //check the bool conqered
	void setIfConquered(bool x); //change the bool

	void calculateScoresByPercent(int squaresNum, int triNum); //calculate the percantage of the board for
	virtual float getShapeScore() { return 0; }					//each shape.



protected:
	sf::Color m_color; //the shape color
	sf::ConvexShape m_shape; //the shape itself
	std::vector<GameObjects*> m_neighbors; //the neighbors vector
	sf::Vector2f m_position; //the position of the shape
	bool conqered; //conqered bool - if its avilble or not.
	float area; //area of the shape.
	std::vector <float> shapesCount; //shapeCountes for the calculate

	float totalShapesScore; //all the shapes *2
	float triScore; //score for each tri.
	float squareScore; //score for each square.

};


