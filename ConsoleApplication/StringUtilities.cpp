#include "StringUtilities.h"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace StringUtilities;


void StringUtilities::toLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), tolower);
}

std::string StringUtilities::toLower(const std::string& str)
{
	std::string output;
	output.resize(str.size());
	std::transform(str.begin(), str.end(), output.begin(), tolower);
	return output;
}

std::vector<std::string> StringUtilities::split(const std::string& str, std::string::value_type splitChar)
{
	std::istringstream stream(str);
	std::string token;
	std::vector<std::string> result;
	while (std::getline(stream, token, splitChar))
	{
		result.push_back(token);
	}

	return result;
}

void StringUtilities::removeSpace(std::string& str)
{
	//std::cout << str.length() << std::endl;
	auto newEnd = std::remove_if(str.begin(), str.end(), isspace);
	str.erase(newEnd, str.end());
	//std::cout << str.length() << std::endl;
	//std::cout << str << std::endl;
}

