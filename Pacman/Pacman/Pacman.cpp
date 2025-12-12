#include "Pacman.hpp"

void Pacman::Controller()
{
}

void Pacman::OnDeath()
{
	_lives--;
	// Check if deaths = 3
	// Respawn at start and restart ghosts, small delay
	
}

void Pacman::EatConsumable(Consumable consumable)
{
	// get points from consumable and add points in game manager
	
}
