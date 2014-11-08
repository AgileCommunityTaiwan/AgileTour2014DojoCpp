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
	else
	{
		ss << val;
		return ss.str();
	}
}