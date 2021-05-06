#include "../colorize.hpp"

int main()
{
	std::string testString{"Hello!"};
	std::cout << printWithColor(testString, Color::red) <<std::endl;

}
