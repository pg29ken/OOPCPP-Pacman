#include "Entity.hpp"


std::pair<int, int> Entity::TryGetNewPosition()
{
	switch (_moveDirection)
	{
	case MoveDirection::UP:
		return { _position.first + 1, _position.second };
	case MoveDirection::DOWN:
		return { _position.first - 1, _position.second };
	case MoveDirection::LEFT:
		return { _position.first, _position.second - 1};
	case MoveDirection::RIGHT:
		return { _position.first, _position.second + 1};
	}
}
void Entity::SetDirection(MoveDirection newDirection)
{
	_moveDirection = newDirection;
}

bool Entity::IsAlive()
{
	return _isAlive;
}

MoveDirection Entity::GetDirection()
{
	return _moveDirection;
}

std::pair<int, int> Entity::GetPosition()
{
	return _position;
}

void Entity::SetPosition(std::pair<int, int> newPosition)
{
	_position = newPosition;
}
