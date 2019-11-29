#pragma once

#include <string>
#include <vector>

namespace StringUtilities
{
	void toLower(std::string& str);
	std::string toLower(const std::string& str);
	std::vector<std::string> split(const std::string& str, std::string::value_type splitChar);
	void removeSpace(std::string& str);
}
