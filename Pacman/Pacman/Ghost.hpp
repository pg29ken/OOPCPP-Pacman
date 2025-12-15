// Copyright @ Ken Arigo - VFS 2025-2026

#include "Utils.hpp"
#include "Entity.hpp"

class Ghost : public Entity
{
public:
	Ghost(std::string Name, std::pair<int, int> Position) : Entity(Name, Position) {}
	void OnDeath() override;
	void ChooseRandomDirection();
	bool IsOppositeDirection(MoveDirection a, MoveDirection b);
private:

};
