#include "../StreamDye.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	std::string output;
	for(int i = 1; i < argc; i++)
	{
		output.append(argv[i]).append(" ");
	}
	std::cout <<StreamDye::effectPrint(output, StreamDye::Effect::blinkSlow)<<std::endl;
}
