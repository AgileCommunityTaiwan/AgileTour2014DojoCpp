#pragma once
#include <string>
#include <sstream>

bool isMultipleOf3(int val)
{
	return (val % 3 == 0);
}

bool isMultipleOf5(int val)
{
	return (val % 5 == 0);
}

bool isContain3(int val)
{
	return (val % 10 == 3) || (val / 10 == 3);
}

bool isContain5(int val)
{
	return (val % 10 == 5) || (val / 10 == 5);
}

std::string convert(int val)
{
	if (val > 100 || val <= 0)
	{
		throw std::invalid_argument("Value should be between 1 from 100!");
	}

	std::ostringstream ss;
	
	if (isMultipleOf3(val) || isContain3(val))
	{
		ss << "Fizz";
	}
	if (isMultipleOf5(val) || isContain5(val))
	{
		ss << "Buzz";
	}
	if (val % 7 == 0)
	{
		ss << "Whizz";
	}
	if (ss.str().empty() )
	{
		ss << val;
	}
	return ss.str();
}