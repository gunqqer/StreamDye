#include "../StreamDye.hpp"
#include <assert.h>
#include <vector>
#include <utility>
#include <iostream>

int main()
{
	//TODO actually write tests, integrate with cmake
	std::string testString{"Hello!"};
	std::vector<std::pair<std::string, std::string>> printTest;
	printTest.push_back(std::make_pair(StreamDye::colorPrint(testString, StreamDye::Color::red), "Red"));
	printTest.push_back(std::make_pair(StreamDye::effectPrint(testString, StreamDye::Effect::bold), "Bold"));
	printTest.push_back(std::make_pair(StreamDye::effectPrint(testString, StreamDye::Effect::blinkSlow), "Blinking"));
	assert(printTest[0].first == "\033[31mHello!\033[39m");
	assert(printTest[1].first == "\033[1mHello!\033[21m");
	assert(printTest[2].first == "\033[5mHello!\033[25m");
	for(auto& i: printTest){std::cout <<i.second <<": " <<i.first <<std::endl;}

}
