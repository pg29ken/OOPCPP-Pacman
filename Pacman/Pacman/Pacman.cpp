#include "Pacman.hpp"

void Pacman::Tick(float deltaTime)
{
	//LOG_LN("dwadhu");
}

void Pacman::SetLives(int newLives)
{
	_lives = newLives;
}

void Pacman::OnDeath()
{
	_lives--;
	// Check if deaths = 3
	// Respawn at start and restart ghosts, small delay
	
}

int Pacman::GetLives()
{
	return _lives;
}

void Pacman::EatConsumable(Consumable consumable)
{
	// get points from consumable and add points in game manager
	
}
