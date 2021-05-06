#include "../colorize.hpp"

int main()
{
	std::string testString{"Hello!"};
	std::cout << StreamDye::printWithColor(testString, StreamDye::Color::red) <<std::endl;

}
