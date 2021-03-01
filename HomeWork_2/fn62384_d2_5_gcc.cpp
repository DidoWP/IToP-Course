/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Daniel Dimitrov Dimitrov
* @idnumber 62384
* @task 5
* @compiler GCC
*
*/
#include<iostream>
#include<limits>
using namespace std;

void Permutation (int** matrix, int line, int Msize);
int SafelyInputInteger (int lowerBound, int UpperBound);
void Swap_Lines (int** matrix, int collumn1, int collumn2);
int** Make_Matrix (int n);

bool MatrixExist = false;

int main()
{
	int n = SafelyInputInteger(1, 10);
	cout << "Input matrix:" << endl;
	int** matrix = Make_Matrix(n);
	cout << endl;
    for(int i=0; i<n; i++)
    {
        Swap_Lines(matrix, 0,i);
        Permutation(matrix, 1, n);
    }
	if (MatrixExist == false) cout << "Does not exist sorted matrix!" << endl;
	return 0;
}

void Permutation(int** matrix, int line, int Msize)
{
	if (MatrixExist == true) return;
	if (line == Msize-1)
	{
        bool check = true;
        for (int i = 1; i < Msize; i++)
        {
            if (matrix[i][i] < matrix[i - 1][i - 1]) { check = false; break; }
        }
        if(check)
        {
            MatrixExist = true;
            cout<<endl;
            for (int i = 0; i < Msize; i++)
            {
                for (int j = 0; j < Msize; j++)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
            cout<<endl;
        }
		return;
	}
	for (int i=line; i<Msize; i++)
	{
	    if (matrix[i][line] >= matrix[line-1][line-1])
		{
		    Swap_Lines(matrix, line, i);
            Permutation(matrix, line + 1, Msize);
		}
	}
	return;
}

int SafelyInputInteger(int lowerBound, int UpperBound)
{
	int intNumber;
	while (true)
	{
		cout << "Input number of lines:";
		cin >> intNumber;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '/n');
			continue;

		}
		if ((intNumber >= lowerBound) && (intNumber <= UpperBound))break;
	}
	return intNumber;
}

void Swap_Lines(int** matrix, int collumn1, int collumn2)
{
	int* temp = matrix[collumn1];
	matrix[collumn1] = matrix[collumn2];
	matrix[collumn2] = temp;
}

int** Make_Matrix(int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int [n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

return matrix;
}
