//
// Created by colin on 08/03/17.
//

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <algorithm>
using namespace std;

class Square
{
private:
	vector<vector<int>> square;
	int size;
public:
	Square(int size);
	void setSquare(vector<vector<int>> temp) { square = temp; }
	vector<vector<int>> getSquare() { return square; }
	int getSize() { return size; }
};
Square::Square(int size)
{
	size = size;
	vector<vector<int>> tempsq(size, vector<int> (size, 0));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			tempsq[i][j] = 0;
		}
	}
	square = tempsq;
}

#endif
