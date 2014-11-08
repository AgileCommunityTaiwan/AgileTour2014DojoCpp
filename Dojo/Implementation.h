#pragma once
#include <string>
#include <sstream>

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

	std::vector<filter_t> filters;
	filters.push_back(filter_t(3, "Fizz"));
	filters.push_back(filter_t(5, "Buzz"));
	filters.push_back(filter_t(7, "Whizz"));

	for (auto i = filters.begin(); i != filters.end(); ++i)
	{
		if (i->filtered(val))
		{
			ss << i->symbol();
		}
	}







	if (isMultipleOf<3>(val) || isContain<3>(val))
	{
		ss << "Fizz";
	}
	if (isMultipleOf<5>(val) || isContain<5>(val))
	{
		ss << "Buzz";
	}
	if (isMultipleOf<7>(val) || isContain<7>(val))
	{
		ss << "Whizz";
	}
	if (ss.str().empty() )
	{
		ss << val;
	}
	return ss.str();
}