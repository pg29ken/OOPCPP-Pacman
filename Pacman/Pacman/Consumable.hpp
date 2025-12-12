// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Object.hpp"

class Consumable : public Object
{
public:
	Consumable(std::string Name, std::pair<int,int> Position) : Object(Name, Position), _points(10) { }
	Consumable(std::string Name) : Object(Name), _points(10) { }
protected:
	int _points;
};