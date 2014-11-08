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
	if (val > 100 || val <= 0)
	{
		throw std::invalid_argument("Value should be between 1 from 100!");
	}

	std::ostringstream ss;
	if (isMultipleOfThree(val) && isMultipleOfFive(val))
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