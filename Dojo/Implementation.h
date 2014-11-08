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

bool isMultipleOf7(int val)
{
	return (val % 7 == 0);
}

template <int base>
bool isMultipleOf(int val)
{
	return (val % base == 0);
}

template <int base>
bool isContain(int val)
{
	return (val % 10 == base) || (val / 10 == base);
}

std::string convert(int val)
{
	if (val > 100 || val <= 0)
	{
		throw std::invalid_argument("Value should be between 1 from 100!");
	}

	std::ostringstream ss;
	
	if (isMultipleOf<3>(val) || isContain<3>(val))
	{
		ss << "Fizz";
	}
	if (isMultipleOf5(val) || isContain<5>(val))
	{
		ss << "Buzz";
	}
	if (isMultipleOf7(val) || isContain<7>(val))
	{
		ss << "Whizz";
	}
	if (ss.str().empty() )
	{
		ss << val;
	}
	return ss.str();
}