/**  Created by cabeatty 1-20-16
 *  There wasn't really anything in class that I did not understand.  So I decided just to
 *  show some fun mathematical principals, namely, a magic square.  And I also allowed the user to
 *  generate one himself.
 *
 *  Wanted to showcase a simple mathematical trick, known as a magic square.
 *  This is essentially a square matrix full of unique integer values, ranging from 1 to the
 *  size row*col, for example a 4x4 array would have a max value of 16, where all the
 *  rows add up to the same number, all the columns add up to the same number,
 *  and both of the diagonals add up to the same value as well.
 *
 *  I give the user the option to either see a randomly generated 4x4 matrix and test it
 *  to check if it is indeed a magic square, or to view a preset magic square.
**/

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include <algorithm>
#include "Headers/solver.h"

using namespace std;

void print(vector<vector<int>> &square, int n)  //Method to do the final pint out of the vector, with the addition listed on the side
{
	vector<int> rows;
	vector<int> cols;

	for (int a = 0; a < n; a++)  //do the addition on the rows and columns
	{
		int tempRow = 0;
		int tempCol = 0;
		for (int l = 0; l < n; l++)
		{
			tempRow = tempRow + square[a][l];
			tempCol = tempCol + square[l][a];
		}
		rows.push_back(tempRow);
		cols.push_back(tempCol);
	}
	//Printing out the magic square and its summations, fancy formatting and all
	for (int row = 0; row < n; row++) //print out the matrix
	{
		for (int col = 0; col < n; col++) {
			cout << "[" << square[row][col] << "] \t";
		}
		cout << "" << rows[row];
		cout << "\n\n";
	}
	for (int i = 0; i < n; i++)
	{
		cout << cols[i] << "\t\t";
	}
}

void generate(vector<vector<int>> &square, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			square[i][j] = 0;
		}
	}

	if (size % 2 == 1)
	{
		cout << "You have selected an odd size magic square." << endl;
		cout << "This is how we solve a magic square of odd size: " << endl;
		odd(square, size);
		print(square, size);     //Final print of the completed square.
		//TODO need to make steps in between, maybe store in a different method and pipe in the steps accordingly from text files?
	}
	else if (size % 4 == 0)
	{
		cout << "You have selected a doubly even size magic square." << endl;
		dEven(square, size);
		print(square, size);    //Final print of the completed square.
	}
	else if (size % 2 == 0)
	{
		cout << "You have selected a singly even size magic square." << endl;
		//sEven(square, size);
	}
}

int main()
{
	hello();
	int q;
	cout << "----------------------------------------------" << endl;
	cout << "Welcome to the magic square learning software!" << endl;
	cout << "----------------------------------------------\n" << endl;
	cout << "Magic Square (Noun):" << endl;
	cout << "In recreational mathematics, a magic square is a NxN square grid (where N is the number of cells on each side)" << endl;
	cout << "filled with distinct positive integers in the range {1 , 2 , . . . , N*N} such that each cell contains a unique"<< endl;
	cout << "integer and the sum of the integers in each row, column and diagonal is equal. The sum is called the magic " << endl;
	cout << "constant or magic sum of the magic square" << endl;
	cout << "\n";
	cout << "Our goal is to teach you how to make magic squares yourself.  Select a size you want to start with:" << endl;
	cout << "Enter an integer value between 3 & 20"<<endl;
	cout << ">";
	cin >> q;
	while( q < 3 || q > 20 )
	{
		cout<<"//ERROR// The number has to be somewhere between 3 and 20"<<endl;
		cout<<"Enter an integer value between 3 & 20"<<endl;
		cout<<">";
		cin >> q;
	}

	vector<vector<int>> square(q, vector<int> (q, 0));
	int diag[2] = {0,0};

	generate(square, q);
}