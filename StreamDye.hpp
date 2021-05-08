#include <concepts>
#include <iostream>
#include <sstream>

namespace StreamDye
{
template<typename T>
concept Printable = requires(T a)
{
	std::cout << a;
};

//global constants
constexpr char prefix[]{"\x1B["}; //needs a number and postfix appended
constexpr char postfix[]{"m"};
constexpr char clear[]{"\033[0m"}; //resets all effects, output this to a stream to clear all ANSI codes


enum class Color //Bright colors are +60
{
	black = 30,
	red = 31,
	green = 32,
	yellow = 33,
	blue = 34,
	magenta = 35,
	cyan = 36,
	white = 37,
	brightBlack = 90,
	brightRed = 91,
	brightGreen = 92,
	brightYellow = 93,
	brightBlue = 94,
	brightMagenta = 95,
	brightCyan = 96,
	brightWhite = 97
};

template<Printable P> std::string printColor(P arg, Color color)
{
	std::stringstream output;
	output <<prefix <<static_cast<int>(color) <<postfix <<arg <<clear;
	return output.str();
}
}
