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

bool isValueTooBig(int val)
{
	return val > 100;
}

std::string convert(int val)
{
	if (isValueTooBig(val) || val <= 0)
	{
		throw std::invalid_argument("Value Too Big!");
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