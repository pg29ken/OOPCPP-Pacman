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

	void Move();
	virtual void Controller() {};
	virtual void OnDeath() {}; // on health = 0 -> different for ghosts and player

protected:
	
	MoveDirection _moveDirection = UP;
	bool _isAlive;

public:
	bool IsAlive();
	MoveDirection GetDirection();
};