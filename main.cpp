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
#include<ctime>
#include<iomanip>
#include <algorithm>

using namespace std;

int main()
{
	srand( time( NULL ) ); //sets the seed for rand()
	int a[4][4];
	int rows[4] = {0, 0, 0, 0};
	int cols[4] = {0, 0, 0, 0};
	int diag[2] = {0, 0};
	int answer = 0;
	bool check = true;
	cout << "Enter '1' to generate a random 4x4 integer matrix and check if it is a magic square."<<endl;
	cout << "Enter any other value to see an actual magic square" << endl <<">";
	cin >> answer;

	//preset the values for a, in case the user wants to see an actual magic square
	a[0][0] = 1;
	a[0][1] = 15;
	a[0][2] = 14;
	a[0][3] = 4;
	a[1][0] = 10;
	a[1][1] = 11;
	a[1][2] = 8;
	a[1][3] = 5;
	a[2][0] = 7;
	a[2][1] = 6;
	a[2][2] = 9;
	a[2][3] = 12;
	a[3][0] = 16;
	a[3][1] = 2;
	a[3][2] = 3;
	a[3][3] = 13;

	if (answer == 1)
	{
		for (int i = 0; i < 4; i++)  //clean the matrix to assist in generating unique numbers
		{
			for (int j = 0; j < 4; j++)
			{
				a[i][j] = 0;
			}
		}
		static vector<int> usedNum;
		usedNum.push_back(0);
		for (int i = 0; i < 4; i++) //fill the matrix with random unique integer values 1-16
		{
			for (int j = 0; j < 4; j++)
			{
				int temp = rand() % 16 + 1;
				if(find(usedNum.begin(), usedNum.end(), temp) != usedNum.end())
				{
					while (find(usedNum.begin(), usedNum.end(), temp) != usedNum.end())
					{
						temp = rand() % 16 + 1;
					}
				}
				usedNum.push_back(temp);
				a[i][j] = temp;
			}
		}
	}

	for (int i = 0; i < 4; i++)  //do the addition on the rows and columns
	{
		for (int j = 0; j <= 3; j++)
		{
			rows[i] = rows[i] + a[i][j];
		}
		for(int k = 0; k < 4; k++)
		{
			cols[i] += a[k][i];
		}
	}

	for (int i = 0; i < 4; i++)  //addition for the diagonals
	{
		diag[0] += a[i][i];
	}
	diag[1] = a[3][0] + a[2][1] + a[1][2] + a[0][3];

	//Printing out the magic square and its summations, fancy formatting and all
	cout << "-----------------------------------\n";
	cout << "\t\t\t\t\t\t\t\t" << diag[1] << "\n\n";
	for (int row = 0; row < 4; row++) //print out the matrix
	{
		for (int col = 0; col < 4; col++) {
			cout << "[" << a[row][col] << "] \t";
		}
		cout << "" << rows[row];
		cout << "\n\n";
	}
	for (int i = 0; i < 4; i++)
	{
		cout << cols[i] << "\t\t";
	}
	cout << diag[0] << endl;

	for (int i = 0; i < 4; i++) //checking on the cols and rows
	{
		if(rows[0] != rows[i] || cols[0] != cols[i])
		{
			check = false;
		}
	}
	if (diag[0] != diag[1])
	{
		check = false;
	}

	cout << "-----------------------------------\n";
	if(check)
		cout<<"This is a magic square!"<<endl;
	if(!check)
		cout<<"This is not a magic square!"<<endl;

	return 0;
}