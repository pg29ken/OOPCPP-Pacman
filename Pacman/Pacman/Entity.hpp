// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"
#include "Object.hpp"

class Entity : public Object
{
public:
	Entity(std::string Name, std::pair<int,int> Position) : Object(Name, Position),  _isAlive(true) {}
	Entity(std::string Name) : Object(Name), _isAlive(true) {}
	Entity() : _isAlive(true) {}


protected:
	
	MoveDirection _moveDirection = UP;
	bool _isAlive;

public:
	virtual void Controller() {};
	virtual void OnDeath() {};

	bool IsAlive();
	void SetDirection(MoveDirection newDirection);
	MoveDirection GetDirection();
	std::pair<int, int> TryGetNewPosition();
	std::pair<int, int> GetPosition();
	void SetPosition(std::pair<int, int> newPosition);
};