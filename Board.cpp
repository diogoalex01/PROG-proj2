#include "Board.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Board::Board(unsigned int rows, unsigned int columns)
{
	this-> rows = rows;
    this-> columns = columns;

}

void Board::make()
{

	xy.resize(rows, vector<char> (columns, '.'));

}

void Board::show()
{
	cout << "   ";
    for (unsigned int i = 97; i < 97 + columns; i++)
    {
        cout << char(i) << ' ';
    }

    cout << endl;

	for (unsigned int k = 0; k < rows; k++)
	{
            cout << char(k + 65) << ' ';

            for (unsigned int j = 0; j < columns; j++)
            {
                cout << ' ' << xy.at(k).at(j);
            }
       
		cout << ' ' << endl;
	}   		
}

void Board::insert(string position, string word)
{
	//this->xy;
	//this->rows;

	// stop
	//if (word == crtl-z)

	char upperCase = position.at(0), lowerCase = position.at(1), orientation = position.at(2);
	unsigned int uC = ((int)upperCase - 65), lC = ((int)lowerCase - 97);

	/////create function just for this
	//verify size
	if ( (((int)upperCase + word.length()) > (65 + rows)) && (((int)lowerCase + word.length()) > (97 + columns)))
	{
		cerr << "That word does not fit in the place you want. Try again!" << endl << endl;
		exit(1);
	}
	//valid size
	else
	{
		if (orientation == 'V')
		{
			for (unsigned int i = uC, k = 0, j = lC; k < word.length(); i++, k++)
			{
				xy.at(i).at(j) = toupper(word.at(k));
			}
		}
		else
		{
			for (unsigned int i = uC, k = 0, j = lC; k < word.length(); j++, k++)
			{
				xy.at(i).at(j) = toupper(word.at(k));
			}
		}
	}
}

bool Board::notUsedWord(string word)
{
	bool notPresent = true;

	for (unsigned int i = 0; i < taken.size(); i++)
	{
		if (taken.at(i) == word)
		{
			notPresent = false;
			cout << "You already used that word";
			break;
		}
		else
			taken.push_back(word);
	}

	return notPresent;
}

/*void Board::occupied(string position, string word)
{
char last = position.at(position.length() - 1);
string coordenates = position.erase(position.size() - 1, 1);
vector<string> aux;
int counter = 0;
string savepos;
bool equal;

while (counter != word.size())
{
int changecolumn = (int)position.at(1) + counter;
int changerow = (int)position.at(0) + counter;

if (last == 'h')
{
savepos = position.at(0) + char(changecolumn);
aux.push_back(savepos);
}

if (last == 'v')
{
savepos = position.at(1) + char(changerow);
aux.push_back(savepos);
}

counter++
}

for (unsigned int i = 0; i < aux.size(); i++)
{
for (unsigned int j = 0; j < positionvec.size(); j++)
{
if (aux.at(i) == positionvec.at(j))
{
if (xy.at(((int)aux.at(i).at(0)) - 'A'), (((int)aux.at(i).at(1)) - 'a') == word.at(i))
{

break;
}
}

}

}
}
*/
string Board::changeDot(string position, string word)
{
	string line;
	char last = position.at(position.length() - 1);
	int j;
	if (last == 'H')
	{
		for (unsigned int i = ((int)position.at(1) - 'a'); i < (columns - ((int)position.at(1) - 'a')); i++)
		{

			j = (int)position.at(0) - 'A';

			if (xy.at(j).at(i) = '.')
			{
				line = line + '?';
			}
			else
			{
				line = line + xy.at(j).at(i);
			}

		}
	}

	if (last == 'V')
	{
		for (unsigned int i = 0; i < (rows - (int)position.at(0) - 'A'); i++)
		{
			j = (int)position.at(1) - 'a';

			if (xy.at(j).at(i) = '.')
			{
				line = line + '?';
			}
			else
			{
				line = line + xy.at(j).at(i);
			}
		}
	}

	cout << line;
	//	d->wildcardMatch(line.c_str(),word.c_str());
	return line;
}



