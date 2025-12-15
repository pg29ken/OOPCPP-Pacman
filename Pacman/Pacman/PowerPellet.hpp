// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Consumable.hpp"

class PowerPellet : public Consumable
{
public:
	PowerPellet(std::string Name, std::pair<int, int> Position) : Consumable(Name, Position) 
	{
		_points = 50;
	}
	void OnConsumed(); // Calls Game Manager -> turns on FreightMode
private:

};