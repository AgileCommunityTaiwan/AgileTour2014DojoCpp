#pragma once
#include <string>
#include <sstream>

std::string convert(int val)
{
	std::ostringstream ss;
	ss << val;
	return ss.str();
}