// Copyright @ Ken Arigo - VFS 2025-2026
#pragma once

#include "Utils.hpp"

class TickManager
{
public:
	TickManager* GetInstance();
private:
	static TickManager* sInstance;
};
TickManager* TickManager::sInstance = nullptr;