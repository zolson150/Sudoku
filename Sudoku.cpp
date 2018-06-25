#include <iostream>

using namespace std;

void printSudoku(int board[][9]) {
	
	cout << "-----------------------" << endl;
	for (int i = 0; i < 9; i++) 
	{
		cout << "| ";
		for (int j = 0; j < 9; j++) 
		{
			cout << board[i][j] << " ";
			//Print every third column.
			if ((j + 1) % 3 == 0)
				cout << "|";
				
		}
		cout << endl;
		//Print every third row.
		if ((i + 1) % 3 == 0)
			cout << "-----------------------" << endl;
	}
	

}

bool checkrow(int board[][9], int row, int number) {
		
	for (int i = 0; i < 9; i++) 
	{
		if (board[row][i] == number)
		{
			//Return false if the row is occupied by "number."
			return false;
		}
	}
	//Return true if the row is unoccupied by "number."
	return true;
}


bool checkColumn(int board[][9], int column, int number) {

	for (int i = 0; i < 9; i++)
	{
		if (board[i][column] == number)
		{
			//Return false if column is occupied by "number".
			return false;
		}
	}
	//Return true if column is occupied by "number".
	return true;
}

bool checkBox(int board[][9], int row, int column, int number) {

	//Move row to first row in box.
	while (row % 3 != 0) row--;
	//Move column to first column in box.
	while (column % 3 != 0) column--;

	for (int i = row; i < row + 3; i++)
	{
		for (int j = column; j < column + 3; j++)
		{
			if (board[i][j] == number)
				//Return false if the number is already contained in the box.
				return false;
		}
		
	}
	//Return true if the number can be placed in box.
	return true;
}

bool findEmptyCell(int board[][9], int &row, int &col) {

	for (row = 0; row < 9; ++row)
	{
		for (col = 0; col < 9; ++col)
		{
			if (board[row][col] == 0)
				return true;
		}
	}
	
	return false;
}


bool solveSudoku(int board[][9]) {

	int row = 0;
	int col = 0;

	//Return if no cells are open.
	if (!findEmptyCell(board, row, col)) 
	{
		return true;
	}

	//Test all values 
	for (int i = 1; i < 10; i++)
	{

		if (checkBox(board, row, col, i) &&
			checkrow(board, row, i) &&
			checkColumn(board, col, i))
		{
			board[row][col] = i;


			if (solveSudoku(board)) {

				return true;
			}

			board[row][col] = 0;
		}
	}


	return false;
}



int main() {

	int sudokuBoard[9][9] = { {0, 9, 4, 0, 0, 6, 5, 2, 0},
							  {0, 0, 0, 5, 9, 8, 6, 0, 0},
							  {0, 8, 5, 0, 0, 0, 9, 0, 7},
							  {0, 0, 0, 0, 2, 0, 0, 0, 9},
							  {0, 5, 9, 3, 0, 1, 7, 6, 0},
							  {8, 0, 0, 0, 6, 0, 0, 0, 0},
							  {0, 7, 8, 1, 0, 0, 2, 4, 0},
							  {3, 0, 1, 0, 0, 0, 8, 9, 0},
							  {0, 0, 6, 8, 4, 9, 0, 0, 0},
	};


	printSudoku(sudokuBoard);

	solveSudoku(sudokuBoard);
	

	cout << endl;
	printSudoku(sudokuBoard);



	return 0;
}