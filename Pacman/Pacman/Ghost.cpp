#include "Ghost.hpp"

void Ghost::Controller()
{
	// Checks directions, if there's a valid direction different choose a random direction to proceed (but not backwards)

	// Ver 2: Pick a target tile and when there's an intersection choose the direction that's closest to the target tile using euclidean distance

	// Ver 3: Choose target tile and move to it

	// Ver 4: 4 AIs with different behaviours to decide their target tile
}

void Ghost::OnDeath()
{
	// Change sprite
	// Pathfind home
}
