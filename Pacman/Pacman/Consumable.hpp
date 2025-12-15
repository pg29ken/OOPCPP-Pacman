// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Object.hpp"

class Consumable : public Object
{
public:
	Consumable(std::string Name, std::pair<int, int> Position) : Object(Name, Position), _points(10) {}
	Consumable(std::string Name) : Object(Name), _points(10) {}
	Consumable() : _points(10) {};
	virtual void OnConsumed() {};

	bool IsActive();
	void SetActiveState(bool state);
	int GetPoints();
protected:
	int _points = 0;
	bool _activated = true;
};