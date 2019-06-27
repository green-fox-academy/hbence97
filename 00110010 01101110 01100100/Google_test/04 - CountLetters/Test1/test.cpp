#include "pch.h"
#include <gtest/gtest.h>
#include "countLetters.h"

TEST(countLettersTest, testShortWord)
{
	//Arrange
	std::map<char, int> output;
	CountLetters word;

	//Act
	output = word.dictionaryOfLetters("apple");

	//Assert
	ASSERT_EQ(output['a'], 1);
	ASSERT_EQ(output['p'], 2);
	ASSERT_EQ(output['l'], 1);
	ASSERT_EQ(output['e'], 1);
}

TEST(countLettersTest, testLongWord)
{
	//Arrange
	std::map<char, int> output;
	CountLetters word;

	//Act
	output = word.dictionaryOfLetters("idontevenknow");

	//Assert
	ASSERT_EQ(output['i'], 1);
	ASSERT_EQ(output['d'], 1);
	ASSERT_EQ(output['o'], 2);
	ASSERT_EQ(output['n'], 3);
	ASSERT_EQ(output['t'], 1);
	ASSERT_EQ(output['e'], 2);
	ASSERT_EQ(output['v'], 1);
	ASSERT_EQ(output['k'], 1);
	ASSERT_EQ(output['w'], 1);
}