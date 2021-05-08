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
constexpr char prefix[]{"\x1B["}; //needs a code and postfix appended
constexpr char postfix[]{"m"};
constexpr char seperator[]{";"}; //Used after prefix and code to add more codes in special ways
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
//Not all effects will be supported by your terminal emulator, be careful when using these
enum class Effects
{
	bold = 1,
	faint = 2, //Not widely supported
	italic = 3, //Not widely supported
	underline = 4,
	blinkSlow = 5,
	blinkFast = 6, //Not widely supported
	reverseForegroundBackground = 7, //also known as [[reverse video]]
	conceal = 8, //Not widely supported
	crossedOut = 9, //Not widely supported
	boldOff = 21, //Not widely supported
	faintOff = 22,
	italicOff = 23,
	underlineOff = 24,
	blinkOff = 25,
	reverseForegroundBackgroundOff = 27,
	concealOff = 28,
	crossedOutOff = 29
};

inline std::string colored(Color color)
{
	std::stringstream output;
	output <<prefix <<static_cast<int>(color) <<postfix;
	return output.str();
}
template<Printable P> std::string printColored(P obj, Color color)
{
	std::stringstream output;
	output <<colored(color) <<obj <<clear;
	return output.str();
}

inline std::string rgbColor(int red, int green, int blue)
{
	constexpr char rgbForeground[]{"38"};
	std::stringstream output;
	output <<prefix <<rgbForeground <<seperator <<"2" <<red <<seperator <<green <<seperator <<blue <<postfix;
	return output.str();
}
template<Printable P> std::string printRgbColor(P obj, int red, int green, int blue)
{
	std::stringstream output;
	output <<rgbColor(red, green, blue) <<obj <<clear;
	return output.str();
}

}


