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

enum class Color //Bright colors are +60
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

template<Printable P> std::string printWithColor(P arg, Color color)
{
	static constexpr char prefix[] = {"\x1B["}; //needs a number and an 'm' appended
	static constexpr char postfix[] ={"\033[0m"}; //resets all effects

	std::stringstream output;
	output <<prefix <<static_cast<int>(color) <<"m" <<arg <<postfix;
	return output.str();
}
}
