// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Object.hpp"

class Consumable : Object
{
public:
	Consumable() : Object(), _points(10) {}
protected:
	int _points;
};