/**  Created by cabeatty 1-20-16
 *	The point of this software is to teach anyone to solve a magic square
**/

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <climits>
#include "Headers/solver.h"

using namespace std;

void print(vector<vector<int>> &square, int n)  //Method to do the final pint out of the vector, with the addition listed on the side
{
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "-- Final Step -- \n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "Now that the square is complete, we will do the addition on the rows, columns, and diagonals to check that our square\n";
	cout << "is an actual magic square.\n\n";

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
		cout << "\n\n\n";
	}
	for (int i = 0; i < n; i++)
	{
		cout << cols[i] << "\t\t";
	}

	cout << "\n\nGreat Job!  \nIt looks like we have made a genuine magic square!\n";
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
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
		cout << "-- You have selected an odd size magic square --" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Since this is an odd size magic square, we know that the magic constant will be S where S = .5*(N^3+N).  \n";
		cout << "For the square you have selected, this constant will be " << S << endl;
		cout << "So we know we will be done solving when all of the rows, columns, and diagonals add up to " << S << ".\n";
		cout << "\nThe general pattern is that we will put each number one column to the right, and one row up from the\n";
		cout << "previous number.  We start this pattern from the middle position of the top row.\n";
		cout << "\nPress any key and enter to continue....\n";
		cin >> enter;

		odd(square, size);
		print(square, size);     //Final print of the completed square.
		//TODO need to make steps in between. Maybe store in a different method and pipe in the steps accordingly from text files?
	}
	else if (size % 4 == 0)
	{
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
		cout << "-- You have selected a doubly even size magic square --\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Since this is a doubly even size magic square, we know that the magic constant will be S where \n";
		cout << "S = .5*(N^3+N).  For the square you have selected, this constant will be " << S << endl;
		cout << "So we know we will be done solving when all of the rows, columns, and diagonals add up to " << S << ".\n";
		cout << "\nPress any key and enter to continue....\n";
		cin >> enter;
		dEven(square, size);
		print(square, size);    //Final print of the completed square.
	}
	else if (size % 2 == 0)
	{
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
		cout << "-- You have selected a singly even size magic square --\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Since this is a singly even size magic square, we know that the magic constant will be S where \n";
		cout << "S = .5*(N^3+N).  For the square you have selected, this constant will be " << S << endl;
		cout << "So we know we will be done solving when all of the rows, columns, and diagonals add up to " << S << ".\n";
		cout << "\nTo start off, we will solve an odd magic square of size (N/2)x(N/2), in this case that square will be of size\n";
		cout<<size/2  << "x" << size/2 << ".  We will then fold 4 of these odd squares back into the original square, and do some  moving around.\n";
		cout << "\nPress any key and enter to continue.\n";
		cin >> enter;
		sEven(square, size);
		print(square, size);
	}
}

int main()
{
	int q;
	bool cond;  //for catching wrong datatype errors
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

	do
	{
		cond = false;
		cout << "Enter an integer value between 3 & 20" << endl;
		cin >> q;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "//ERROR// not an integer value //ERROR//\n";
			cond = true;
		}
		else if (q < 3 || q > 20)
		{
			cout << "//ERROR// integer value must be between 3 & 20 //ERROR//\n";
			cond = true;
		}
	}
	while (cond);

	vector<vector<int>> square(q, vector<int> (q, 0));
	int diag[2] = {0,0};
	generate(square, q);
}