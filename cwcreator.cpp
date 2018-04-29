#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	int rows, columns;
	
	cout << "How many rows: ";

	cin >> rows;

	cout << "How many columns: ";
	
	cin >> columns;

	Board board(rows, columns);
	board.make();
	board.show();

	
	return 0;
}


/*
cwcreator
main.cpp
Extraction of a word list from a synonym dictionary
@author Diogo & Mafalda
@version 1.0 29/04/2018
*/
