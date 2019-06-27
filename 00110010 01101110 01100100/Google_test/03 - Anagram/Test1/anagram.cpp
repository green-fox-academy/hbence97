#include "pch.h"
#include "anagram.h"

bool Anagram::isAnagram(std::string string1, std::string string2)
{
	std::sort(string1.begin(), string1.end());
	std::sort(string2.begin(), string2.end());
	return string1 == string2;
}