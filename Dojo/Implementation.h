#pragma once
#include <string>
#include <sstream>

std::string convert(int val)
{
	std::ostringstream ss;
	if (val == 3)
	{
		return "Fizz";
	}
	else if (val == 5)
	{
		return "Buzz";
	}
	else
	{
		ss << val;
		return ss.str();
	}
}