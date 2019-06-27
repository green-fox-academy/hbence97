#include "pch.h"
#include "countLetters.h"

std::map<char, int> CountLetters::dictionaryOfLetters(std::string input)
{
	std::map<char, int> lettersMap;
	for (int i = 0; i < input.size(); i++)
	{
		lettersMap[input.at(i)]++;
	}
	return lettersMap;
}
