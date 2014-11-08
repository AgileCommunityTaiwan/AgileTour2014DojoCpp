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

TEST_F(MyTest, InputMultipleOfThree)
{
	EXPECT_EQ("Fizz", convert(3));
	EXPECT_EQ("Fizz", convert(6));
	EXPECT_EQ("Fizz", convert(9));

}

TEST_F(MyTest, InputMultipleOfFive)
{
	EXPECT_EQ("Buzz", convert(5));
	EXPECT_EQ("Buzz", convert(10));
}

TEST_F(MyTest, InputMultipleof15)
{
	EXPECT_EQ("FizzBuzz", convert(15));
	EXPECT_EQ("FizzBuzz", convert(45));
}

TEST_F(MyTest, InputTooBig)
{
	EXPECT_THROW(convert(101), std::invalid_argument);
}

TEST_F(MyTest, InputTooSmall)
{
	EXPECT_THROW(convert(0), std::invalid_argument);
}
