// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"

class Object
{
public:
	Object() : _name("Object"), _position(0,0) {}
	Object(std::string Name, std::pair<int,int> Position) : _name(Name), _position(Position){ }
	Object(std::string Name) : _name(Name), _position({0,0}) { }
protected:
	std::string _name;
	std::pair<int, int> _position;
};