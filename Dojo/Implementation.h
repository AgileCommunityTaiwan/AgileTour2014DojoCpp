#pragma once
#include <string>
#include <sstream>

bool isMultipleOfThree(int val)
{
	return (val % 3 == 0);
}

bool isMultipleOfFive(int val)
{
	return (val % 5 == 0);
}

std::string convert(int val)
{
	std::ostringstream ss;
	if (val % 15 == 0)
	{
		return "FizzBuzz";
	}
	else if (isMultipleOfThree(val))
	{
		return "Fizz";
	}
	else if (isMultipleOfFive(val))
	{
		return "Buzz";
	}
	else
	{
		ss << val;
		return ss.str();
	}
}