#include "../StreamDye.hpp"

int main()
{
	//TODO actually write tests, integrate with cmake
	std::string testString{"Hello!\n"};
	std::cout <<StreamDye::printColor(testString, StreamDye::Color::red);
	std::cout <<StreamDye::printEffect(testString, StreamDye::Effect::bold);

}
