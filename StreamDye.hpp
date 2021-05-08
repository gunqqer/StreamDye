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


enum class Color
{
	black = 30,
	red = 31,
	green = 32,
	yellow = 33,
	blue = 34,
	magenta = 35,
	cyan = 36,
	white = 37
};
enum class BrightColor
{
	brightBlack = 90,
	brightRed = 91,
	brightGreen = 92,
	brightYellow = 93,
	brightBlue = 94,
	brightMagenta = 95,
	brightCyan = 96,
	brightWhite = 97
};
enum class Effects
{
	bold = 1,
	faint = 2, //NWS
	italic = 3, //NWS
	underline = 4,
	blinkSlow = 5,
	blinkFast = 6, //NWS
	reverseForegroundBackground = 7, //Why though
	conceal = 8, //NWS
	crossedOut = 9, //NWS
	boldOff = 21, //NWS
	faintOff = 22,
	italicOff = 23,
	underlineOff = 24,
	blinkOff = 25,
	reverseForegroundBackgroundOff = 27,
	concealOff = 28,
	crossedOutOff = 29
};

template<Printable P> std::string printColor(P obj, Color color)
{
	std::stringstream output;
	output <<prefix <<static_cast<int>(color) <<postfix <<obj <<clear;
	return output.str();
}
}
