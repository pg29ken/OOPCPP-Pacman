// Copyright @ Ken Arigo - VFS 2025-2026
#pragma once

#include "Utils.hpp"
#include <vector>
#include <functional>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
using TickDelegateSignature = std::function<void(float)>;

class TickManager
{
public:
	static TickManager* GetInstance();

    void RegisterDelegate(const TickDelegateSignature& tickDelegate);
    void Tick(float deltaTime);
    void StartAutoTick(unsigned intervalMs = 16);
    void StopAutoTick();
private:
    TickManager();
	static TickManager* sInstance;

    std::vector<TickDelegateSignature> _delegates;
    std::mutex _mut;


    std::atomic<bool> _autoTickRunning;
    std::thread _autoTickThread;

    // Delete copy operations
    TickManager(const TickManager&) = delete;
    TickManager& operator=(const TickManager&) = delete;
};


class TickObject
{
public:
    TickObject();
    virtual  ~TickObject();
    virtual void Tick(float deltaTime);
};