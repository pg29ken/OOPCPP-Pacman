#pragma once
#include <iostream>
#include <string>
#include <vector>

#define LOG(X) std::cout << X
#define LOG_LN(X) std::cout << X << std::endl
#define LOG_EMPTY_LN() LOG("")

enum MoveDirection
{
	UP,
	RIGHT,
	LEFT,
	DOWN
};


// Colors

#define WHITE_BG "\033[47;30m"
#define RESET_COLORS "\033[0m"
#define BLUE "\033[34m"
