// Copyright @ Ken Arigo - VFS 2025-2026
#pragma once

#include "Utils.hpp"
#include "Entity.hpp"

class Ghost : public Entity
{
public:
	Ghost(std::string Name, std::pair<int, int> Position) : Entity(Name, Position) {}
	void OnDeath() override;
	void ChooseRandomDirection();
	bool IsOppositeDirection(MoveDirection a, MoveDirection b);
	bool IsActive();
	void KillGhost();
private:
	bool _isActive = true;
	void Tick(float deltaTime) override;

	float _ghostRespawnTimer = 0.0f;
	const float _ghostRespawnDuration = 4.0f;
};
