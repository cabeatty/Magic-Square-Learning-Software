/**
 * Created by colin on 15/02/17.
 * This class will contain methods for solving odd magic squares
**/

#ifndef MIDTERM_ALT_ODD_H
#define MIDTERM_ALT_ODD_H

using namespace std;
void odd(vector<vector<int>> &square, int n)
{
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
			square[i][j] = num++; //set number

		j++;
		i--; //1st condition

	}
}

#endif //MIDTERM_ALT_ODD_H
