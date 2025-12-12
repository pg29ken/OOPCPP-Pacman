#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <format>

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