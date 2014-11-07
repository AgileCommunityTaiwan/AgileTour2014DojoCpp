#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <string>
#include <iterator>
#include <memory>
#include <limits>
#include <algorithm>

using namespace std;
using namespace testing;

std::string SplitDelimiters(const string &delimitersting, string &remainString)
{
	std::size_t prev = 0, pos;
	prev = delimitersting.find("//");
	pos = delimitersting.find("\n");

	if (prev == std::string::npos)
		return "";
	
	remainString = delimitersting.substr(pos + 2, 2);
	return delimitersting.substr(prev + 2, pos - prev -2);
}

vector<std::string> SplitWithMultipleDelimiters(const string &numbers, const string& delimiters)
{
	std::stringstream stringStream(numbers);
	std::string line = numbers;
	vector<std::string> wordVector;
	//while (std::getline(stringStream, line))
	{
		std::size_t prev = 0, pos;
		while ((pos = line.find_first_of(delimiters, prev)) != std::string::npos)
		{
			if (pos >= prev)
				wordVector.push_back(line.substr(prev, pos - prev));

			prev = pos + 1;
		}
		if (prev <= line.length())
			wordVector.push_back(line.substr(prev, std::string::npos));
	}

	return wordVector;
}

vector<int> ConvertStringToVectorInt(const string &numbers)
{
	vector<int> results;
	vector<string> numberStrings = SplitWithMultipleDelimiters(numbers, ",\n");
	for (auto numberStringEntry : numberStrings)
	{
		if (numberStringEntry.empty())
			throw std::exception();

		long long number = 0;
		istringstream(numberStringEntry) >> number;
		
		if (number > std::numeric_limits<int>::max())
			throw std::exception();

		results.push_back(number);
	}

	return results;
}

int Add(string numbers)
{
	if (numbers.empty())
		return 0;
	
	vector<int> vecTotalNum = ConvertStringToVectorInt(numbers);

	long long int sum = 0;
	for (int i = 0; i < vecTotalNum.size(); ++i)
	{
		sum += vecTotalNum[i];
	}

	int int_max = std::numeric_limits<int>::max();

	if (sum > int_max) throw std::exception();

	return sum;
}

//int AddDefine(string numbers)
//{
//	if (numbers.empty())
//		return 0;
//	
//	string sDefineDelimiters = SplitDelimiters(numbers, remainString);
//	vector<string> vecTotalNum = SplitWithMultipleDelimiters(sDefineDelimiters);
//
//	long long int sum = 0;
//	for (int i = 0; i < vecTotalNum.size(); ++i)
//	{
//		sum += vecTotalNum[i];
//	}
//
//	int int_max = std::numeric_limits<int>::max();
//
//	if (sum > int_max) throw std::exception();
//
//	return sum;
//}

class StringCalculatorTest : public ::testing::Test
{
};

class SplitWithMultipleDelimitersTest : public ::testing::Test
{
};

TEST_F(StringCalculatorTest, Sum)
{
	EXPECT_EQ(0, Add(""));
	EXPECT_EQ(1, Add("1"));
	EXPECT_EQ(3, Add("1,2"));
}

TEST_F(StringCalculatorTest, Sum_Many)
{
	EXPECT_EQ(55, Add("1,2,3,4,5,6,7,8,9,10"));

	ostringstream outputStream;
	outputStream << "1,2,3,4,5,6,7,8,9,10," << std::numeric_limits<int>::max();

	EXPECT_THROW(Add(outputStream.str()), std::exception);

}

TEST_F(StringCalculatorTest, Sum_ManyMany)
{
	EXPECT_EQ(55, Add("1,2,3,4,5,6,7,8,9,10"));

	{
		ostringstream outputStream;
		outputStream << std::numeric_limits<long long int>::max();
		EXPECT_THROW(Add(outputStream.str()), std::exception);
		outputStream << ",1,2,3,4,5,6,7,8,9,10";
		EXPECT_THROW(Add(outputStream.str()), std::exception);
	}
	{
		ostringstream outputStream;
		outputStream << std::numeric_limits<int>::max();
		EXPECT_NO_THROW(Add(outputStream.str()));
	}
}

TEST_F(StringCalculatorTest, Sum_MultiLine)
{
	EXPECT_EQ(6, Add("1\n2,3"));
	EXPECT_THROW(Add("1,\n"), std::exception);
}

TEST_F(SplitWithMultipleDelimitersTest, Split)
{	
	EXPECT_THAT(SplitWithMultipleDelimiters("1,2,3", ","), 
				ElementsAre("1", "2", "3"));

	EXPECT_THAT(SplitWithMultipleDelimiters("1,2,\n3", ",\n"), 
				ElementsAre("1", "2", "", "3"));

	EXPECT_THAT(SplitWithMultipleDelimiters(",,1,2,\n\n3,,", ",\n"),
				ElementsAre("", "","1", "2", "", "","3", "", ""));

	EXPECT_THAT(SplitWithMultipleDelimiters("", ",\n"), 
			    ElementsAre(""));
}

TEST_F(StringCalculatorTest, Sum_with_different_delimiters)
{
	{
		string remainingStr;
		EXPECT_EQ(";", SplitDelimiters("//;\n", remainingStr));
		EXPECT_EQ("", remainingStr);
	}
	
	{
		string remainingStr;
		EXPECT_EQ(",;", SplitDelimiters("//,;\n", remainingStr));
		EXPECT_EQ("", remainingStr);
	}

	{
		string remainingStr;
		EXPECT_EQ(",;", SplitDelimiters("//,;\n\n", remainingStr));
		EXPECT_EQ("", remainingStr);
	}

	{
		string remainingStr;
		EXPECT_EQ("", SplitDelimiters("//\n", remainingStr));
		EXPECT_EQ("", remainingStr);
	}

	{
		string remainingStr;
		EXPECT_EQ("", SplitDelimiters("", remainingStr));
		EXPECT_EQ("", remainingStr);
	}
}

TEST_F(StringCalculatorTest, Sum_with_different_define_delimiters)
{
	//EXPECT_EQ(3, AddDefine("//;\n1;2"));
}