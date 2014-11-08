#include "gtest/gtest.h"
#include "Implementation.h"
using namespace std;

class MyTest : public ::testing::Test
{
};

TEST_F(MyTest, InputNormalNumber)
{
	EXPECT_EQ("1", convert(1));
	EXPECT_EQ("2", convert(2));
}

TEST_F(MyTest, InputThree)
{
	EXPECT_EQ("Fizz", convert(3));
}

TEST_F(MyTest, InputFive)
{
	EXPECT_EQ("Buzz", convert(5));
}
