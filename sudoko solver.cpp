#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#define N 9

using namespace std;

 

bool FindFreeSpace(int Sudoku_Grid[N][N], int &row, int &col);

bool isSafe(int Sudoku_Grid[N][N], int row, int col, int num);

 
 
bool SolveSudoku(int Sudoku_Grid[N][N])

{

    int row=0, col=0;

    if (!FindFreeSpace(Sudoku_Grid, row, col))

       return true;

    for (int num = 1; num <= 9; num++)

    {

        if (isSafe(Sudoku_Grid, row, col, num))

        {

            Sudoku_Grid[row][col] = num;

            if (SolveSudoku(Sudoku_Grid))

                return true;

            Sudoku_Grid[row][col] = 0;

        }

    }

    return false;

}

 
 
bool FindFreeSpace(int Sudoku_Grid[N][N], int &row, int &col)

{

    for (row = 0; row < N; row++)

        for (col = 0; col < N; col++)

            if (Sudoku_Grid[row][col] == 0)

                return true;

    return false;

}

 
 
bool UsedInRow(int Sudoku_Grid[N][N], int row, int num)

{

    for (int col = 0; col < N; col++)

        if (Sudoku_Grid[row][col] == num)

            return true;

    return false;

}

 
 
bool UsedInCol(int Sudoku_Grid[N][N], int col, int num)

{

    for (int row = 0; row < N; row++)

        if (Sudoku_Grid[row][col] == num)

            return true;

    return false;

}

 

 
bool UsedInBox(int Sudoku_Grid[N][N], int boxStartRow, int boxStartCol, int num)

{

    for (int row = 0; row < 3; row++)

        for (int col = 0; col < 3; col++)

            if (Sudoku_Grid[row+boxStartRow][col+boxStartCol] == num)

                return true;

    return false;

}
 
bool isSafe(int Sudoku_Grid[N][N], int row, int col, int num)

{

    return !UsedInRow(Sudoku_Grid, row, num) && !UsedInCol(Sudoku_Grid, col, num) &&

           !UsedInBox(Sudoku_Grid, row - row % 3 , col - col % 3, num);

} 
 

/* print Sudoku_Grid  */

void printSudoku(int Sudoku_Grid[N][N])

{

    for (int row = 0; row < N; row++)

    {

        for (int col = 0; col < N; col++)
		{ 
			{
			cout<<Sudoku_Grid[row][col]<<"  ";
		    }
		}
 
            

        cout<<endl;

    }

}

 


int main()

{

    int Sudoku_Grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},

                      {5, 2, 0, 0, 0, 0, 0, 0, 0},

                      {0, 8, 7, 0, 0, 0, 0, 3, 1},

                      {0, 0, 3, 0, 1, 0, 0, 8, 0},

                      {9, 0, 0, 8, 6, 3, 0, 0, 5},

                      {0, 5, 0, 0, 9, 0, 6, 0, 0},

                      {1, 3, 0, 0, 0, 0, 2, 5, 0},

                      {0, 0, 0, 0, 0, 0, 0, 7, 4},

                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	cout<<Sudoku_Grid[i][j]<<" ";
	cout<<endl;
}
cout<<"\n\nSolution Of Given Puzzle!!\n\n";
    if (SolveSudoku(Sudoku_Grid) == true)

          printSudoku(Sudoku_Grid);

    else

        cout<<"SORRY :( \nDoes not Found Any Solution"<<endl;

    return 0;

}
