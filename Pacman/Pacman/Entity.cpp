#include "Entity.hpp"


void Entity::Move()
{
	std::pair<int, int> checkPos;
	switch (_moveDirection)
	{
	case MoveDirection::UP:
		checkPos = { _position.first + 1, _position.second };
	case MoveDirection::DOWN:
		checkPos = { _position.first - 1, _position.second };
	case MoveDirection::LEFT:
		checkPos = { _position.first, _position.second - 1};
	case MoveDirection::RIGHT:
		checkPos = { _position.first, _position.second + 1};
	}

	//If ( checo board[first][seccon] == Obhect.getname("Wall"))
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

