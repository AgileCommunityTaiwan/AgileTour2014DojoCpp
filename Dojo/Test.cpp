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


