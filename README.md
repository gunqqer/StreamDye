# StreamDye
A simple header only C++ lib that can colorize most object's output with ANSI color codes

# Requirements
To use this header you need a compiler which supports \<concepts\>.

`gcc` 10 and `clang` 10 should both support this.

# Using
`#include "StreamDye.hpp"` and use `StreamDye::printWithColor(Object obj, StreamDye::Color color)` to get a string which can easily be output to `std::cout`

All colors are defined in the header.

# Building

To build the sample code, you will need CMake and Make (and as above, c++20 support with support for \<concepts\>).
```
mkdir -p build;
cmake ..
make
```
All binaries will be put into the root of the build directory. For information on what each binary does, read the cpp file it was compiled from.

# Contributing
Please open pull requests to improve this. I will appreciate any contribution.

# Contact
It is preferred if you open an issue on [Github](https://github.com/gunqqer/StreamDye) but if you need, [email me](mailto:StreamDye@friithian.dev).
