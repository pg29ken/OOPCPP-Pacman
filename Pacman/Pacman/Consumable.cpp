#include "Consumable.hpp"

bool Consumable::IsActive()
{
    return _activated;
}

void Consumable::SetActiveState(bool state)
{
    _activated = state;
}

int Consumable::GetPoints()
{
    return _points;
}
