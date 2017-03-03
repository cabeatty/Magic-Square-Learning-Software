/**
 * Created by colin on 15/02/17.
 * This class will contain methods for solving s-even magic squares
**/
#ifndef solver
#define solver

#include <string>

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
						cout << "+";
					else
						cout << "-";
				}
				if (flag != 1)  //For after the switch, to show the new positions
				{
					if (row < p)
						cout << "-";
					else
						cout << "+";
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

//--------------------------------------------------------------------------------------------------------------------/
//--------------------------------------------------<ODD>-------------------------------------------------------------/
//--------------------------------------------------------------------------------------------------------------------/

void odd(vector<vector<int>> &square, int n)
{
	int messInd = 0;
	string messages[5] =
			{"Since this is the first step, we simply put a 1 in the middle spot on the top row.",
			 "Since one row up is outside the square, we go one column right, and place the number in the bottom row of that column.",
			 "Since one column right is outside the square, we go one row up, and place the number in the first column of that row.",
			 "Since one column right and one row up is already filled, we simply put the number in the position below the last.",
			 "We place the next number one column to the right, and one row up."
			};
	int x = n / 2;  //Center of the square
	int y = 0;
	//starting at the center on the top row with 1, we put the next number one square right, and one square up
	//repeating this process until we get to n;
	for (int i = 1; i <= n * n; i++)
	{
		square[y][x] = i;
		step(i);
		cout << messages[messInd] << endl << endl;
		printStep(square, n);
		pause();

		int tempx = x + 1;
		int tempy = y - 1;
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
		if (square[tempy][tempx] == 0)
		{
			x = tempx;
			y = tempy;
		}
		if (square[tempy][tempx] != 0)
		{
			messInd = 3;
			y++;
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------/
//-----------------------------------------------<DoublyEven>---------------------------------------------------------/
//--------------------------------------------------------------------------------------------------------------------/

void dEven(vector<vector<int>> &square, int n)
{
	//TODO: steps and visualizeation
	int i, j;
	int st = 1;
	char enter;
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

	step(st++);
	cout << "We start by filling up a blank " << n << "*" << n << " square linearly, like follows.\n\n";
	printStep(square, n);
	pause();

	step(st++);
	if (n != 4)
	{
		cout << "We then also fill two other " << n << "*" << n << " squares by splitting them into " << n/2 << " 4x4 quadrants, and then filling the middle 2 rows with\n";
		cout << "1's for all the quadrants in the first square.  And filling the middle 2 columns with ones for all of the quadrants in\n";
		cout << "the second square.  They will be as follows: \n";
	}
	else
	{
		cout << "We then also fill two other " << n << "*" << n << " squares by filling the middle n/2 rows with 1's for the first square.\n";
		cout << "And filling the middle n/2 columns for the second square.  They will be as follows: \n";
	}
	cout << "\n--\n\n";
	printStep(I, n);
	cout << "\n--\n\n";
	printStep(J, n);
	cout << "We will use these two extra squares to find the positions on the original square where we will be\n";
	cout << "doing some computation to find the actual values that we want there.  Essentially, we want to modify\n";
	cout << "all values of the original square, where their position falls on a space where the two above squares\n";
	cout << "have equal values.  We will call these the indexing squares.\n\n";
	pause();

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (I[i][j] == J[i][j])
			{
				int temp = I[i][j];
				square[i][j] = n * n + 1 - square[i][j];
				step(st++);
				cout << "Since the values in the space (" << i+1 << ", " << j+1 << ") in the indexing squares are both " << temp << " we will take the value\n";
				cout <<	"in that same position in the original square and subtract it from n*n+1, in this case getting " << square[i][j] << ".\n\n";
				printStep(square, n);
				pause();
			}
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------/
//-----------------------------------------------<SinglyEven>---------------------------------------------------------/
//--------------------------------------------------------------------------------------------------------------------/

void sEven(vector<vector<int>> &square, int n)
{
	//This one is a pain in the ass, especially with the description
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

	char enter;
	int p = n / 2;
	int max = p * p;  //Proportional additive for the quadrants
	int ind = max;  //for indexing the steps and not changing the value of max
	int i, j;

	vector<vector<int>> quadrant(p, vector<int>(p, 0));  //We need an odd magic square of length half N
	odd(quadrant, p);
	step(ind++);
	cout << "Now that that is done, we fold said odd magic square back into the original, like follows:\n\n";

	for (i = 0; i < p; i++) //filling all of the quadrants at once
		for (j = 0; j < p; j++)
		{
			square[i][j] = quadrant[i][j];      //Top left
			square[i][j + p] = quadrant[i][j];    //Top right
			square[i + p][j] = quadrant[i][j];    //Bottom left
			square[i + p][j + p] = quadrant[i][j];  //Bottom right
		}

	printStep(square, n);
	pause();

	step(ind++);
	cout << "Now that that is done, we add the max value in the top right quadrant, to all of the values in the bottom \n";
	cout << "right quadrant.  In this case that number is " << max << ".\n\n";

	for (i = 0; i < p; i++) //doing the addition on the bottom right quadrant
		for (j = 0; j < p; j++)
		{
			square[i + p][j + p] += max;      //Bottom right (adding p to each)
		}
	printStep(square, n);
	pause();

	step(ind++);
	cout << "Now that that is done, we add the max value in the bottom left quadrant, to all of the values in the top \n";
	cout << "right quadrant.  In this case that number is " << max * 2 << ".\n\n";
	for (i = 0; i < p; i++) //doing the addition on the top right
		for (j = 0; j < p; j++)
		{
			square[i][j + p] += (max * 2);    //Top right (adding 2*p to each)
		}
	printStep(square, n);
	pause();

	step(ind++);
	cout << "Now that that is done, we add the max value in the top right quadrant, to all of the values in the bottom \n";
	cout << "left quadrant.  In this case that number is " << max * 3 << ".\n\n";
	for (i = 0; i < p; i++) //doing the addition on the bottom left quadrant
		for (j = 0; j < p; j++)
		{
			square[i + p][j] += (max * 3);    //Bottom left (adding 3*p to each)
		}
	printStep(square, n);
	pause();

	step(ind++);
	cout << "Now we have to do some switching around.  The square is almost complete, but some things have to be moved around\n";
	cout << "to make it work.  Look at the numbers with '-' next to them, we are going to switch them with their counterpart\n";
	cout << "in the quadrant below.  These are the numbers with a '+' next to them.\n\n";
	vector<vector<int>> markColLeft(p, vector<int>(p, 0));
	int markL = p / 2;
	for (i = 0; i < p; i++)
		for (j = 0; j < p; j++)
		{
			if (i != markL)
			{
				if (j < markL)
				{
					markColLeft[i][j] = 1;
				}
				else
				{
					markColLeft[i][j] = 0;
				}
			}
			else
			{
				if (j < markL + 1)
				{
					markColLeft[i][j] = 1;
				}
				else
				{
					markColLeft[i][j] = 0;
				}
				markColLeft[i][0] = 0;
			}
		}
	vector<vector<int>> markColRight(p, vector<int>(p, 0));
	int markR = n % 3;
	if (n == 18)
		markR = 3;
	for (i = 0; i < p; i++)
		for (j = 0; j < p; j++)
		{
			markColRight[i][j] = 0;
			if (j >= p - markR)
			{
				markColRight[i][j] = 1;
			}
		}
	vector<vector<int>> markVector(n, vector<int>(n, 0));
	for (i = 0; i < p; i++) //filling all of the quadrants at once
		for (j = 0; j < p; j++)
		{
			markVector[i][j] = markColLeft[i][j];      //Top left
			markVector[i][j + p] = markColRight[i][j];    //Top right
			markVector[i + p][j] = markColLeft[i][j];    //Bottom left
			markVector[i + p][j + p] = markColRight[i][j];  //Bottom right
		}
	printStepMarked(square, markVector, n, 1);
	pause();

	step(ind++);
	cout << "With the switching done, we see the new ordering of the square.\n\n";
	//Now I do the actual swapping
	int tempL, tempR;
	for (i = 0; i < p; i++) //filling all of the quadrants at once
		for (j = 0; j < p; j++)
		{
			if (markColLeft[i][j] == 1)  //We only have to work in quadrants, so I only need two loops.  This one is for the lhs
			{
				tempL = square[i][j];
				square[i][j] = square[i + p][j];
				square[i + p][j] = tempL;
			}
			if (markColRight[i][j] == 1)  //This one is for the rhs
			{
				tempR = square[i][j + p];
				square[i][j + p] = square[i + p][j + p];
				square[i + p][j + p] = tempR;
			}
		}
	printStepMarked(square, markVector, n, 0);
	pause();
}

#endif