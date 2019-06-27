#include "pch.h"
#include <gtest/gtest.h>
#include "apple.h"

TEST(appleTest, testOutputString) {

	apple apple;
	std::string output = apple.getApple();
	EXPECT_EQ(output, "apple");
}