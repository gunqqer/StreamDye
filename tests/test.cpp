#include "../StreamDye.hpp"

int main()
{
	std::string testString{"Hello!"};
	std::cout << StreamDye::printColor(testString, StreamDye::Color::red) <<std::endl;

}
