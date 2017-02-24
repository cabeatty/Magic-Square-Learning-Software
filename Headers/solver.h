/**
 * Created by colin on 15/02/17.
 * This class will contain methods for solving s-even magic squares
**/
#define MIDTERM_ALT_SINGLYEVEN_H

#include <string>

using namespace std;

void printStep(vector<vector<int>> &square, int n)  //Method to do the final pint out of the vector, with the addition listed on the side
{
	//Printing out the magic square and its summations, fancy formatting and all
	for (int row = 0; row < n; row++) //print out the matrix
	{
		for (int col = 0; col < n; col++)
		{
			cout << "[" << square[row][col] << "] \t";
		}
		cout << "\n\n";
	}
}

void odd(vector<vector<int>> &square, int n)
{
	int messInd = 0;
	string messages[5] =
			{   "Since this is the first step, we simply put a 1 in the middle spot on the top row.",
				"Since one row up is outside the square, we go one column right, and place the number in the bottom row of that column.",
			    "Since one column right is outside the square, we go one row up, and place the number in the first column of that row.",
			    "Since one column right and one row up is already filled, we simply put the number in the position below the last.",
			    "We place the next number one column to the right, and one row up."
			};
	char enter; //For press any key and enter to continue
	int x = n/2;  //Center of the square
	int y = 0;
	//starting at the center on the top row with 1, we put the next number one square right, and one square up
	//repeating this process until we get to n;
	for(int i = 1; i <= n*n; i++)
	{
		square[y][x] = i;

		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-- Step " << i <<" --" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl << messages[messInd] << endl << endl;
		printStep(square, n);
		cout << "Press any key and enter to continue.\n";
		cin >> enter;
		cout << endl;

		int tempx = x+1;
		int tempy = y-1;
		messInd = 4;
		if (tempx >= n)
		{
			messInd = 2;
			tempx = 0;
		}
		if (tempy <= -1)
		{
			messInd = 1;
			tempy = (n - 1);
		}
		if(square[tempy][tempx] == 0)
		{
			x = tempx;
			y = tempy;
		}
		if(square[tempy][tempx] != 0)
		{
			messInd = 3;
			y++;
		}
	}
}

void dEven(vector<vector<int>> &square, int n)
{
	int i, j;
	vector<vector<int>> I(n, vector<int>(n, 0));
	vector<vector<int>> J(n, vector<int>(n, 0));
	int index = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			I[i][j] = ((i + 1) % 4) / 2;
			J[j][i] = ((i + 1) % 4) / 2;
			square[i][j] = index;
			index++;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (I[i][j] == J[i][j])
			{
				square[i][j] = n * n + 1 - square[i][j];
			}
		}
	}
}

void sEven(vector<vector<int>> &square, int n)
{
	char enter;
	//TODO sudden realization about singly even numbers.
	/* Essentially all singly even numbers can be broken down into an odd times 2.
	 * Which means that all we need to do is divide the singly even square into 4
	 * odd squares (one for each quadrant) and solve each in the right order.
	 * Then put them all back together.
	 */

	/* Better idea:  Each quadrant will be the same pattern, just with proportionally larger numbers.
	 * I will solve only one odd size square, then I will add the largest number in the former quadrant
	 * to it to as I fold it back into the original square, in the correct order.  This should be much
	 * easier to understand for people who already know how to solve odd magic squares.
	 * Thankfully this software already does, so we will make use of that instead of writing another
	 * algorithm all together.
	 */

	//There will be an extra step at the end where we switch some numbers around, but that is it past solving an odd.
	//TODO make this step

	int p = n / 2;
	int max = p*p;  //Proportional additive for the quadrants
	int ind = max;  //for indexing the steps and not changing the value of max
	int i, j;
	vector<vector<int>> quadrant(p, vector<int>(p, 0));
	odd(quadrant, p);
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-- Step " << ind++ <<" --" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "Now that that is done, we fold said odd magic square back into the original, like follows:" << endl << endl;

	for (i=0; i<p; i++) //filling all of the quadrants at once
		for (j=0; j<p; j++ )
		{
			square[i][j] = quadrant[i][j];      //Top left
			square[i][j+p] = quadrant[i][j];    //Top right
			square[i+p][j] = quadrant[i][j];    //Bottom left
			square[i+p][j+p] = quadrant[i][j];  //Bottom right
		}
	printStep(square, n);
	cout << "Press any key and enter to continue.\n";
	cin >> enter;
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-- Step " << ind++ <<" --" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "Now that that is done, we add the max value in the top right quadrant, to all of the values in the bottom " << endl;
	cout << "right quadrant.  In this case that number is " << max << "." << endl << endl;
	for (i=0; i<p; i++) //doing the addition on the bottom right quadrant
		for (j=0; j<p; j++ )
		{
			square[i+p][j+p] += max;      //Bottom right (adding p to each)
		}
	printStep(square, n);
	cout << "Press any key and enter to continue.\n";
	cin >> enter;
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-- Step " << ind++ <<" --" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "Now that that is done, we add the max value in the bottom left quadrant, to all of the values in the top " << endl;
	cout << "right quadrant.  In this case that number is " << max*2 << "." << endl << endl;
	for (i=0; i<p; i++) //doing the addition on the top right
		for (j=0; j<p; j++ )
		{
			square[i][j+p] += (max*2);    //Top right (adding 2*p to each)
		}
	printStep(square, n);
	cout << "Press any key and enter to continue.\n";
	cin >> enter;
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "-- Step " << ind++ <<" --" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "Now that that is done, we add the max value in the top right quadrant, to all of the values in the bottom " << endl;
	cout << "left quadrant.  In this case that number is " << max*3 << "." << endl << endl;
	for (i=0; i<p; i++) //doing the addition on the bottom left quadrant
		for (j=0; j<p; j++ )
		{
			square[i+p][j] += (max*3);    //Bottom left (adding 3*p to each)
		}
	printStep(square, n);
	cout << "Press any key and enter to continue.\n";
	cin >> enter;
	cout << endl;

}