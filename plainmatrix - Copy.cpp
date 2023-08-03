/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                      Question-a) Plain Matrix
*******************************************************************************/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int MAX = 3;
class matrix
{
private:
	int mat[MAX][MAX];

public:
	void create();
	void display();
	void additionmat(matrix &mat1, matrix &mat2);
	void subtractionmat(matrix &mat1, matrix &mat2);
	void multiplicationmat(matrix &mat1, matrix &mat2);
};
void matrix::create()
{
	for (int m = 0; m < MAX; m++) //rows
	{
		for (int n = 0; n < MAX; n++) //column
		{
			cin >> mat[m][n];
		}
	}
}
void matrix::additionmat(matrix &mat1, matrix &mat2)
{
	for (int m = 0; m < MAX; m++) //rows
	{
		for (int n = 0; n < MAX; n++) //column
		{
			mat[m][n] = mat1.mat[m][n] + mat2.mat[m][n];
		}
	}
}
void matrix::subtractionmat(matrix &mat1, matrix &mat2)
{
	for (int m = 0; m < MAX; m++) //rows
	{
		for (int n = 0; n < MAX; n++) //column
		{
			mat[m][n] = mat1.mat[m][n] - mat2.mat[m][n];
		}
	}
}
void matrix::multiplicationmat(matrix &mat1, matrix &mat2)
{
	for (int k = 0; k < MAX; k++) //row
	{
		for (int m = 0; m < MAX; m++) ///column 2
		{
			mat[k][m] = 0;
			for (int n = 0; n < MAX; n++) //column 1
			{
				mat[k][m] = mat[k][m] + mat1.mat[k][n] * mat2.mat[n][m];
			}
		}
	}
}
void matrix::display()
{
	for (int m = 0; m < MAX; m++) //rows
	{
		for (int n = 0; n < MAX; n++) //column
		{
			cout << mat[m][n] << " ";
		}
		cout << endl; //to get spce in next line
	}
}
int main()
{
	matrix mat1, mat2, mat3;
	cout << "enter 1st matrix: " << endl;
	mat1.create();
	cout << "enter 2nd matrix: " << endl;
	mat2.create();
	cout << "1st matrix: " << endl;
	mat1.display();
	cout << "2nd matrix: " << endl;
	mat2.display();
	mat3.additionmat(mat1, mat2);
	cout << "addtion of 2 matrix: " << endl;
	mat3.display();
	cout << "substraction of 2 matrix: " << endl;
	mat3.subtractionmat(mat1, mat2);
	mat3.display();
	cout << "multiplication of 2 matrix: " << endl;
	mat3.multiplicationmat(mat1, mat2);
	mat3.display();
	return 0;
}
