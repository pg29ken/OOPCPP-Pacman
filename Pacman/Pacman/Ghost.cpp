#include "Ghost.hpp"
#include <random>


void Ghost::OnDeath()
{
	// Change sprite
	// Pathfind home
}

#include <cstdlib>  // for rand()
#include <ctime>    // for time()

void Ghost::ChooseRandomDirection()
{
    static const std::vector<MoveDirection> directions = { UP, DOWN, LEFT, RIGHT };

    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }

    std::vector<MoveDirection> canMoveDirections;
    for (MoveDirection dir : directions)
    {
        if (!IsOppositeDirection(dir, _moveDirection))
            canMoveDirections.push_back(dir);
    }

    if (canMoveDirections.empty())
        canMoveDirections = directions;

    int index = std::rand() % canMoveDirections.size();
    _moveDirection = canMoveDirections[index];
}


// Helper to check if two directions are opposites
bool Ghost::IsOppositeDirection(MoveDirection a, MoveDirection b)
{
    return (a == UP && b == DOWN) ||
        (a == DOWN && b == UP) ||
        (a == LEFT && b == RIGHT) ||
        (a == RIGHT && b == LEFT);
}

void Ghost::Tick(float deltaTime)
{
    if (_isActive == false)
    {
        _ghostRespawnTimer -= deltaTime;
        if (_ghostRespawnTimer <= 0.0f)
        {
            _isActive = true;
            _ghostRespawnTimer= 0.0f;
        }
    }
}

bool Ghost::IsActive()
{
    return _isActive;
}

void Ghost::KillGhost()
{
    _isActive = false;
    _ghostRespawnTimer = _ghostRespawnDuration;
}

