#include "../StreamDye.hpp"
#include <assert.h>
int main()
{
	//TODO actually write tests, integrate with cmake
	std::string testString{"Hello!"};
	assert(StreamDye::printColor(testString, StreamDye::Color::red) == "\033[31mHello!\033[39m");
	assert(StreamDye::printEffect(testString, StreamDye::Effect::bold) == "\033[1mHello!\033[21m");

}
