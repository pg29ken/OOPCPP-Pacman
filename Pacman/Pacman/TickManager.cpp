#include "TickManager.hpp"

TickManager* TickManager::GetInstance()
{
	if (sInstance)
	{
		return sInstance;
	}
	sInstance = new TickManager();
	return sInstance;
}
