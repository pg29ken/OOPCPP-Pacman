// Copyright @ Ken Arigo - VFS 2025-2026
#pragma once

#include "Utils.hpp"
#include "Entity.hpp"
#include "Consumable.hpp"

class Pacman : public Entity
{
public:
	Pacman() : Entity(), _lives(0) 
	{
		_name = "Pacman";
		_position = { 26, 15 };
	}

	void Tick(float deltaTime) override;
	void Controller() override;

private:
	int _lives;

	void OnDeath() override;
	void EatConsumable(Consumable consumable);
};