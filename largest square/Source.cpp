#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	bool end = false; 
	int R[1];
	int C[1];
	ifstream inputFile;
	// opens file setting R array to number of rows and C array to contain the number of columns 
	inputFile.open("test.txt");
	while(end == false) {
		inputFile >> R[0];
		inputFile >> C[0];
		
		//takes the number of rows and columns inside the previous arrays and places them inside ints 
		int rows = R[0];
		int columns = C[0];
		if (rows == 0) {
			end = true;
		}
		

			// Create 2d Dynamic array 
			int **ary = new int*[rows];
			for (int i = 0; i < rows; ++i) {
				ary[i] = new int[columns];
			}
			// Load Rows and Columns into array 
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					inputFile >> ary[i][j];
				}
			}
			// Displays Original 2D data 
			/*
			for (int i = 0; i < rows; ++i) {
				cout << endl;
				for (int j = 0; j < columns; ++j) {
					cout << ary[i][j];
				}
			}
			cout << endl;
			*/
			// creates Anwser array 
			int **aryA = new int*[rows];
			for (int i = 0; i < rows; ++i) {
				aryA[i] = new int[columns];
			}

			int Scount = 0;

			for (int C = 0; C < columns; C++)
			{
				for (int R = 0; R < rows; R++)
				{
					if (ary[R][C] == 1)
					{
						if (R == 0 or C == 0)
						{
							aryA[R][C] = 1;
						}
						else if (R > 1 && C > 1 && aryA[R - 1][C - 1] == aryA[R - 1][C] && aryA[R - 1][C - 1] == aryA[R][C - 1] && aryA[R - 1][C - 1] > 1)
						{
							aryA[R][C] = aryA[R - 1][C - 1] + 1;

						}
						else if(R > 1 && C > 1 && aryA[R - 1][C - 1] == aryA[R - 1][C] +1 & aryA[R - 1][C - 1] == aryA[R][C - 1] +1)
						{
							aryA[R][C] = aryA[R - 1][C - 1] + 1;
						}
						else if (R > 1 && C > 1 && aryA[R - 1][C] == aryA[R - 1][C-1] + 1 & aryA[R-1][C] == aryA[R][C - 1] + 1)
						{
							aryA[R][C] = aryA[R - 1][C - 1] + 1;
						}
						else if (R > 1 && C > 1 && aryA[R][C-1] == aryA[R -1][C - 1] + 1 & aryA[R][C-1] == aryA[R-1][C] + 1)
						{
							aryA[R][C] = aryA[R - 1][C - 1] + 1;
						}
						else if (R > 1 && C > 1 && ary[R - 1][C - 1] == 1 && ary[R - 1][C] == 1 && ary[R][C - 1] == 1)
						{
							aryA[R][C] = 2;

						}

						if (ary[R][C] == 1 && aryA[R][C] < 2) {
							aryA[R][C] = 1;
						}


					}
					if (ary[R][C] == 0)
					{
						aryA[R][C] = 0;
					}
				}
			}
			/*
			for (int i = 0; i < rows; ++i) {
				cout << endl;
				for (int j = 0; j < columns; ++j) {
					cout << aryA[i][j];
				}
			}
			*/
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < columns; ++j) {
					if (aryA[i][j] > Scount)
						Scount = aryA[i][j];
				}
			}
			if (rows != 0) {
				cout << endl << Scount;
			}
		}
	
	return 0;
}




