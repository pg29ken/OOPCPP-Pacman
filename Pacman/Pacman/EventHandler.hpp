// Copyright @ Ken Arigo - VFS 2025-2026

#pragma once
#include "Utils.hpp"

class EventHandler
{
public: // switch to private and make as singleton
	EventHandler();

private:
	void TickFunction();
};