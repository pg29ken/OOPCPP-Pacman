// Copyright @ Ken Arigo - VFS 2025-2026

#include "Utils.hpp"
#include "Entity.hpp"

class Ghost : Entity
{
public:
	Ghost(std::string Name, std::pair<int, int> Position) : Entity(Name, Position) {}
	void Controller() override;
	void OnDeath() override;
private:

};
