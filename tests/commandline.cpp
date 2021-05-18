#include "../StreamDye.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	std::string output;
	for(int i = 1; i < argc; i++)
	{
		output.append(argv[i]);
	}
	std::cout <<StreamDye::effectPrint(output, StreamDye::Effect::conceal)<<std::endl;
}
