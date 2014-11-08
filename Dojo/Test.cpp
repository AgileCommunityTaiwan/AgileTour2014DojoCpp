#include "gtest/gtest.h"
#include "Implementation.h"
using namespace std;

class MyTest : public ::testing::Test
{
};

TEST_F(MyTest, InputOne)
{
	EXPECT_EQ("1", convert(1));
}

