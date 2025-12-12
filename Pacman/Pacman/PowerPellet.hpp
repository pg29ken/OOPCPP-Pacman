// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Consumable.hpp"

class PowerPellet : Consumable
{
public:
	void OnConsume(); // Calls Game Manager -> turns on FreightMode
private:

};