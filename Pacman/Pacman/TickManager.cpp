#include "TickManager.hpp"

TickManager* TickManager::sInstance = nullptr;
TickManager* TickManager::GetInstance()
{
	if (sInstance)
	{
		return sInstance;
	}
	sInstance = new TickManager();
	return sInstance;
}

void TickManager::RegisterDelegate(const TickDelegateSignature& tickDelegate)
{
	std::lock_guard<std::mutex> lock(_mut);
	_delegates.push_back(tickDelegate);
}

TickObject::TickObject()
{
	if (TickManager::GetInstance())
	{
		TickManager::GetInstance()->RegisterDelegate(std::bind(&TickObject::Tick, this, std::placeholders::_1));
	}
}

TickObject::~TickObject()
{
}

void TickManager::Tick(float deltaTime)
{
	std::lock_guard<std::mutex> lock(_mut);
	for (TickDelegateSignature& tickDelegate : _delegates)
	{
		tickDelegate(deltaTime);
	}
}

void TickManager::StartAutoTick(unsigned intervalMs)
{
	if (_autoTickRunning) return;
	_autoTickRunning = true;

	_autoTickThread = std::thread([this, intervalMs]() {
		using clock = std::chrono::high_resolution_clock;
		auto prev = clock::now();

		while (_autoTickRunning)
		{
			auto now = clock::now();
			std::chrono::duration<float> duration = now - prev;
			prev = now;

			Tick(duration.count());

			std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
		}
	});
}

void TickManager::StopAutoTick()
{
	_autoTickRunning = false;
	if (_autoTickThread.joinable())
		_autoTickThread.join();
}

TickManager::TickManager()
{
	_autoTickRunning = false;
}

void TickObject::Tick(float deltaTime) {}
