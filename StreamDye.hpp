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
constexpr char prefix[]{"\x1B["}; //Needs a code and postfix appended to actually do anything, mostly for internal use
constexpr char postfix[]{"m"}; //Mostly for internal use
constexpr char seperator[]{";"}; //Used after prefix and code to add more codes in special ways, mostly for internal use
constexpr char clear[]{"\033[0m"}; //resets all effects, output this to a stream to clear all ANSI codes


enum class Color
{
	reset = 22, //Also resets intensity
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
	reset = 22, //Also resets intensity
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
constexpr int effectResetOffset = 20;
enum class Effect
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
	//Off codes are the on codes +20
	boldOff = 21, //Not widely supported
	faintOff = 22, //Also turns off color
	italicOff = 23,
	underlineOff = 24,
	blinkOff = 25,
	blinkFastOff = 25, //Codes for resetting both blinks are the same
	reverseForegroundBackgroundOff = 27,
	concealOff = 28,
	crossedOutOff = 29
};

inline std::string resetAll(){return clear;}

//These are pairs of functions that work together
//The first returns a string that will enable the code and must be manually disabled
//by outputting StreamDye::clear to the same stream or the corresponding Effect::xxxxxOff
//
//The second takes an object as well as the args the first function requires
//This will enable the code, output the object, then disable it
inline std::string color(Color c)
{
	std::stringstream output;
	output <<prefix <<static_cast<int>(c) <<postfix;
	return output.str();
}
template<Printable P> std::string printColor(P obj, Color c)
{
	std::stringstream output;
	output <<color(c) <<obj <<Color::reset;
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
	output <<rgbColor(red, green, blue) <<obj <<Color::reset;
	return output.str();
}

inline std::string effect(Effect e) //If used, you must either remember the effect used or use resetAll() to turn it off
{
	std::stringstream output;
	output <<prefix <<static_cast<int>(e) <<postfix;
	return output.str();
}
template<Printable P> std::string printEffect(P obj, Effect e)
{
	std::stringstream output;
	output <<effect(e) <<obj <<static_cast<int>(e)+effectResetOffset;
	return output.str();
}

}


