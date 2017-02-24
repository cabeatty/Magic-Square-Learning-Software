/**
 * Created by colin on 15/02/17.
 * This class will contain methods for solving s-even magic squares
**/
#define MIDTERM_ALT_SINGLYEVEN_H

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
	//TODO: visualization.  print the square at each step
	int i = n / 2;
	int j = n - 1;

	for (int num = 1; num <= n * n;) {
		if (i == -1 && j == n) //3rd condition
		{
			j = n - 2;
			i = 0;
		}
		else
		{
			if (j == n) //1st condition helper if next number goes to out of square's right side
				j = 0;
			if (i < 0)  //1st condition helper if next number is goes to out of square's upper side
				i = n - 1;
		}
		if (square[i][j]) //2nd condition
		{
			j -= 2;
			i++;
			continue;
		} else
		{
			cout << "-----------------------------------" << endl;
			cout << "Step " << num << endl << endl;
			square[i][j] = num++; //set number
			printStep(square, n);
		}
		//TODO print should probably be here, where we actually make changes

		j++;
		i--; //1st condition

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
	int p = n / 2;
	vector<vector<int>> M(p, vector<int>(p, 0));

	int i, j, k, temp;

	for (i = 0; i < p; i++)
	{
		for (j = 0; j < p; j++)
		{
			square[i][j] = M[i][j];
			square[i + p][j] = M[i][j] + (3 * p * p);
			square[i][j + p] = M[i][j] + (2 * p * p);
			square[i + p][j + p] = M[i][j] + (p * p);
		}
	}
	if (n != 2)  //if the matrix is 2*2 we are already done, and the square finished
	{
		//this is where it gets real fucking tricky, and we see why we really need vectors and their operations
		vector<int> I(p, 0);
		vector<int> J(n, 0);

		for (i = 1; i < p; i++)
			I[i] = i + 1;

		k = (n - 2) / 4;
		for (i = 1; i <= k; i++)
			J.push_back(i);
		for (i = n - k + 2; i <= n; i++)
			J.push_back(i);

		//now the ordering of the main matrix, square, using the constituant vectors, I & J, which we have already generated
		//We essentaily use the vectors as an index guide (I for col, J for row) to reorder square close to what we want
		for (i = 1; i <= p; i++)
		{
			for (j = 1; j <= J.size(); j++)
			{
				//basic swap operations in a specific order
				temp = square[i - 1][J[j - 1] - 1];
				square[i - 1][J[j - 1] - 1] = square[i + p - 1][J[j - 1] - 1];
				square[i + p - 1][J[j - 1] - 1] = temp;
			}
		}

		//two more swaps to manage the final cases
		i = k;
		j = 0;
		temp = square[i][j];
		square[i][j] = square[i + p][j];
		square[i + p][j] = temp;
		j = i;
		temp = square[i + p][j];
		square[i + p][j] = square[i][j];
		square[i][j] = temp;
	}
}

void gen(vector<vector<int>> &square, int size)  //Will probably need this for the sEven square solver
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
		//TODO need to make steps in between, maybe store in a different method and pipe in the steps accordingly from text files?
	}
	else if (size % 4 == 0)
	{
		cout << "You have selected a doubly even size magic square." << endl;
		dEven(square, size);
	}
	else if (size % 2 == 0)
	{
		cout << "You have selected a singly even size magic square." << endl;
		sEven(square, size);
	}
}