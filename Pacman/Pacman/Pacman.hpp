// Copyright @ Ken Arigo - VFS 2025-2026
#pragma once

#include "Utils.hpp"
#include "Entity.hpp"
#include "Consumable.hpp"

class Pacman : public Entity
{
public:
	Pacman() : Entity(), _lives(3) 
	{
		_name = "Pacman";
		_position = { 26, 15 };
	}
	Pacman(std::pair<int,int> startPos) : Entity(), _lives(3) 
	{
		_name = "Pacman";
		_position = { startPos.first, startPos.second };
	}

	void Tick(float deltaTime) override;
	void SetLives(int newLives);
	void OnDeath() override;
	int GetLives();
private:
	int _lives;

	void EatConsumable(Consumable consumable);
};