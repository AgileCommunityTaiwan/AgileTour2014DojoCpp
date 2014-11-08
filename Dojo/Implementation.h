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
	
	if (isMultipleOfThree(val) || val ==13)
	{
		ss << "Fizz";
	}
	if (isMultipleOfFive(val))
	{
		ss << "Buzz";
	}
	if (ss.str().empty() )
	{
		ss << val;
	}
	return ss.str();
}