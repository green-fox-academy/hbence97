#include "pch.h"
#include <gtest/gtest.h>
#include "anagram.h"

TEST(anagramTest, testIsAnagram)
{
	Anagram anagram;
	bool output = anagram.isAnagram("listen", "silent");
	ASSERT_EQ (output, true);
}

TEST(anagramTest, testNotAnagram)
{
	Anagram anagram;
	bool output = anagram.isAnagram("tired", "testing");
	ASSERT_EQ (output, false);
}