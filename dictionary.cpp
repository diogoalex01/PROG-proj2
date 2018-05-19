#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

Dictionary::Dictionary(string thesaurusFile)
{
	string key;
	ifstream fin;

	fin.open(thesaurusFile);

	//checks wether the indicated file is valid
	if (!fin.is_open())
	{
		cerr << "Input file not found!\n";
		exit(1);
	}

	string next;
	string words;

	this->synonyms;


	//extracts the header words to a vector
	while (!fin.eof())
	{
		getline(fin, next);

		for (unsigned int i = 0; i < next.length(); i++)
		{
			//deletes the space in the beggining of the word
			if (next.at(0) == ' ')
			{
				next.erase(0, 1);
			}

			if (next.at(i) == ':')
			{
				key = caps(next.substr(0, i));
				next.erase(next.begin(), next.begin() + (i + 1));
				i = 0;
			}
			if (next.at(i) == ',')
			{
				synonyms.push_back(caps(next.substr(0, i)));
				next.erase(next.begin(), next.begin() + (i + 1));
				i = 0;
			}
			if (i == (next.length() - 1))

			{
				synonyms.push_back(caps(next));
			}
		}

		//cout << synonymes.size() << endl;


		validWords.insert(pair <string, vector<string> >(key, synonyms));


		synonyms.clear();

	}

	fin.close();
}
//writes the words in caps
string Dictionary::caps(string word)
{

	for (unsigned int i = 0; i < word.size(); i++)
	{
		word.at(i) = toupper(word.at(i));
	}
	return word;
}

//checks if the word is in the thesaurus file
bool Dictionary::isValid(string word, map<string, vector<string> > validWords)
{
	bool present = false;
	this->validWords;
	string newWord = caps(word);
	map<string, vector<string> >::iterator it;

	it = validWords.find(word);
	if (it != validWords.end())
	{
		present = true;
	}


	return present;
}
