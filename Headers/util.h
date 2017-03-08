/**
 * Created to house some of the functions that I wanted to seperate from the solver.h file
 * Put some new things in here as well
 *
 */

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <algorithm>
using namespace std;

void printStep(vector<vector<int>> &square, int n)  //All this will do is print out the matrix at a step determined by other methods
{
	for (int row = 0; row < n; row++) //print out the matrix
	{
		for (int col = 0; col < n; col++)
		{
			cout << "[" << square[row][col] << "] \t";
		}
		cout << "\n\n";
		if (row < n-1)
		{
			cout << "\n";
		}
	}
}

//print out the matrix for the switching step in singly even case
void printStepMarked(vector<vector<int>> &square, vector<vector<int>> &markup, int n, int flag)
{
	int p = n / 2;
	for (int row = 0; row < n; row++) //print out the matrix
	{
		for (int col = 0; col < n; col++)
		{
			cout << "[" << square[row][col] << "]";
			if (markup[row][col] == 1)
			{
				if (flag == 1)  //For before the switch
				{
					if (row < p)
					{
						cout << "+";
					} else
					{
						cout << "-";
					}
				}
				if (flag != 1)  //For after the switch, to show the new positions
				{
					if (row < p)
					{
						cout << "-";
					}
					else
					{
						cout << "+";
					}
				}
			}

			cout << " \t";
		}
		cout << "\n\n";
		if (row < n-1)
		{
			cout << "\n";
		}
	}
}

void step(int i)
{
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "-- Step " << i << " --\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
}

void pause()
{
	char e;
	cout << "Press any key and enter to continue.\n";
	cin >> e;
	cout << endl;
}

vector<vector<int>> swap(vector<vector<int>>& square, int i1, int j1, int i2, int j2)
{
	int temp = square[i1][j1];
	square[i1][j1] = square[i2][j2];
	square[i2][j2] = temp;
	return square;
}


#endif