#pragma once

#include "NeuralNetwork.h"
#include "Net.h" 
#include <SFML/Graphics.hpp>


using namespace std;

using namespace sf;

struct Data
{
	vector<double> inputs; 
	vector<double> target; 
	Data(double x, double y, double answer)
	{
		inputs.push_back(x); 
		inputs.push_back(y); 
		target.push_back(answer); 
	}

};

vector<Data> training { Data(1,1,0), Data(0,0,0),Data(1,0,1), Data(0, 1 , 1) };  // training data 

vector<unsigned> topology ={2, 4,   1};

vector<vector<RectangleShape>> grid;
Net nn(topology); 
const unsigned width = 500, height = 500,epochs = 2000 , resolution = 10, rows = height / resolution, cols = width / resolution; // resolution is going to be how large the squares are going to be 
void initGrid()
{
	for (int i = 0; i < rows; i++)
	{
		grid.push_back(vector<RectangleShape>()); 
		for (int j = 0; j < cols; j++)
		{
			RectangleShape  rect(Vector2f(resolution, resolution));
			rect.setPosition(i * resolution, j * resolution);
			
			
			rect.setOutlineColor(Color::Black);
			

			grid[i].push_back(rect);
		}
	}
	
}

void initNet()   // this inits the net then trains it for and Epoch number of times 
{

}


void draw(RenderWindow* window)
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			double x = grid[i][j].getPosition().x / width;
			double y = grid[i][j].getPosition().y / height;
			vector<double> pos{ x,y };
			vector<double> color;
			nn.feedForward(pos);
			nn.getResults(color);
			grid[i][j].setFillColor(Color::Color(color[0] * 255));
			window->draw(grid[i][j]);
		}
	}
}

void update()
{
	for (int i = 0; i < 100; i++)
	{
		Data temp = training[(rand() % training.size())];

	
	nn.feedForward(temp.inputs);
	nn.backProp(temp.target);
	vector<double> results; 
	nn.getResults(results); 
	cout << temp.inputs[0] << ", " << temp.inputs[1] << "   " << temp.target[0] <<"  Guess: "<< results[0] << endl;
	}
}