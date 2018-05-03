#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Dictionary::Dictionary(string thesaurusFile)
{
	ifstream fin;
	fin.open(thesaurusFile);

	//checks wether the indicated file is valid
	if (!fin.is_open())
	{
		cerr << "Input file not found!\n";
		exit(1);
	}

	/////////////////////////////////////////////
	/*
	cout << "Word list file? ";
	cin >> wordFile;

	ofstream fout; //fout
	fout.open(wordFile);

	//checks wether the indicated file is valid
	if (!fout.is_open())
	{
	cerr << "Output file opening failed.\n";
	exit(2);
	}
	*/

	string next;

	while (!fin.eof())
	{
		getline(fin, next);

		for (unsigned int i = 0; i < next.length(); i++)
		{
			if (next.at(i) == ':')
			{
				validWords.push_back(next.substr(0, i));
				break;
			}
		}
	}

	for (unsigned int i = 0; i < validWords.size(); i++)
		cout << validWords.at(i) << endl;
    

	fin.close();
	//fout.close();
}

bool Dictionary::isValid(string word)
{
	bool present = false;
    this->validWords;

	for (unsigned int i = 0; i < validWords.size(); i++)
	{
		if (word == validWords.at(i))
		{
			present = true;
			break;
		}
	}

    return present;
}



bool wildcardMatch(const char *str, const char *strWild)
{
	// We have a special case where string is empty ("") and the mask is "*".
	// We need to handle this too. So we can't test on !*str here.
	// The loop breaks when the match string is exhausted.
	while (*strWild)
	{
		// Single wildcard character
		if (*strWild == '?')
		{
			// Matches any character except empty string
			if (!*str)
				return false;
			// OK next
			++str;
			++strWild;
		}
		else if (*strWild == '*')
		{
			// Need to do some tricks.
			// 1. The wildcard * is ignored.
			// So just an empty string matches. This is done by recursion.
			// Because we eat one character from the match string,
			// the recursion will stop.
			if (wildcardMatch(str, strWild + 1))
				// we have a match and the * replaces no other character
				return true;
			// 2. Chance we eat the next character and try it again,
			// with a wildcard * match. This is done by recursion.
			// Because we eat one character from the string,
			// the recursion will stop.
			if (*str && wildcardMatch(str + 1, strWild))
				return true;
			// Nothing worked with this wildcard.
			return false;
		}
		else
		{
			// Standard compare of 2 chars. Note that *str might be 0 here,
			// but then we never get a match on *strWild
			// that has always a value while inside this loop.
			if (toupper(*str++) != toupper(*strWild++))
				return false;
		}
	}
	// Have a match? Only if both are at the end...
	return !*str && !*strWild;
}