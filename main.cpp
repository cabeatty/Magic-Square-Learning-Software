/**  Created by cabeatty 1-20-16
 *	The point of this software is to teach anyone to solve a magic square
**/

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "Headers/solver.h"

using namespace std;

void print(vector<vector<int>> &square, int n)  //Method to do the final pint out of the vector, with the addition listed on the side
{
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "The final square will look like: \n" << endl;
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
	double exp = pow ( (double)size, 3.0);
	double S = (exp + size) * .5;
	char enter; //placeholder for press enter to continue breaks
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			square[i][j] = 0;
		}
	}

	if (size % 2 == 1)
	{
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-- You have selected an odd size magic square --" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;
		cout << "Since this is an odd size magic square, we know that the magic constant will be S where S = .5*(N^3+N).  " << endl;
		cout << "For the square you have selected, this constant will be " << S << endl;
		cout << "So we know we will be done solving when all of the rows, columns, and diagonals add up to " << S << "." << endl;
		cout << "\nThe general pattern is that we will put each number one column to the right, and one row up from the" << endl;
		cout << "previous number.  We start this pattern from the middle position of the top row." << endl;
		cout << "Press any key and enter to continue.\n";
		cin >> enter;

		odd(square, size);
		print(square, size);     //Final print of the completed square.
		//TODO need to make steps in between. Maybe store in a different method and pipe in the steps accordingly from text files?
	}
	else if (size % 4 == 0)
	{
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-- You have selected a doubly even size magic square --" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;
		cout << "Since this is a doubly even size magic square, we know that the magic constant will be S where " << endl;
		cout << "S = .5*(N^3+N).  For the square you have selected, this constant will be " << S << endl;
		cout << "So we know we will be done solving when all of the rows, columns, and diagonals add up to " << S << "." << endl;
		cout << "\nPress any key and enter to continue.\n";
		cin >> enter;
		dEven(square, size);
		print(square, size);    //Final print of the completed square.
	}
	else if (size % 2 == 0)
	{
		cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-- You have selected a singly even size magic square --" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;
		cout << "Since this is a singly even size magic square, we know that the magic constant will be S where " << endl;
		cout << "S = .5*(N^3+N).  For the square you have selected, this constant will be " << S << endl;
		cout << "So we know we will be done solving when all of the rows, columns, and diagonals add up to " << S << "." << endl;
		cout << "\nThis is how we solve a magic square of singly even size: " << endl;
		cout << "Press any key and enter to continue.\n";
		cin >> enter;
		sEven(square, size);
		//print(square, size);
		//TODO make this work
	}
}

int main()
{
	int q;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-- Welcome to the magic square learning software! --" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;
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