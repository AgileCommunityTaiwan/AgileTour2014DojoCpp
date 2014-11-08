#pragma once
#include <string>
#include <sstream>

std::string convert(int val)
{
	std::ostringstream ss;
	if (val == 15)
	{
		return "FizzBuzz";
	}
	else if (val % 3 == 0)
	{
		return "Fizz";
	}
	else if (val % 5 == 0)
	{
		return "Buzz";
	}
	else
	{
		ss << val;
		return ss.str();
	}
}