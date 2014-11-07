#include "gtest/gtest.h"
using namespace std;

class MyTest : public ::testing::Test
{
};


TEST_F(MyTest, Test1)
{
	EXPECT_EQ(2, 1 + 1);
}

