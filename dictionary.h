#ifndef dictionary_h
#define dictionary_h

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dictionary
{
public:
	Dictionary(string thesaurusFile);
	bool isValid(string word);
	bool wildcardMatch(const char *str, const char *strWild);

private:
	vector<string> validWords;
};

#endif