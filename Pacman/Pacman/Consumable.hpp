// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Object.hpp"

class Consumable : Object
{
public:
	Consumable(std::pair<int,int> Position) : Object(Position), _points(10) { }
	Consumable(std::string Name) : Object(Name), _points(10) { }
protected:
	int _points;
};