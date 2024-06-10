#include <iostream>
#include <string>
#include <regex>

int main(int argc, char* argv[])
{
	std::regex reg1("1");
	std::string s;
	std::cin >> s;
	if (!std::regex_search(s, reg1))
	{
		std::cout << 1;
	}
	std::regex reg2("[*1]*");
	std::string s1;
	std::cin >> s1;
	if (std::regex_match(s1, reg2))
	{
		std::cout << 1;
	}
	return EXIT_SUCCESS;
}