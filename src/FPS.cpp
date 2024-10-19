#include "SDL2/SDL.h"

#include "Mechanics/FPS.hpp"

Game::Mechanics::FPS::FPS(int p_fps)
{
    accumulator = 0.00f;
	currentFrameIndex = 0;
	
	fps = p_fps;
	
	previousTime = SDL_GetPerformanceCounter();
	deltaTime = 1.0f / fps;
}

void Game::Mechanics::FPS::Init()
{
    currentTime = SDL_GetPerformanceCounter();
    elapsedTime = (currentTime - previousTime) / (float)SDL_GetPerformanceFrequency();
		
	previousTime = currentTime;
	accumulator += elapsedTime;
		
	frameTimes[currentFrameIndex] = elapsedTime;
	currentFrameIndex = (currentFrameIndex + 1) % MAX_FRAME_HISTORY;
	if (currentFrameIndex > MAX_FRAME_HISTORY)
	{
		currentFrameIndex = MAX_FRAME_HISTORY;
	}
		
	averageFrameTime = 0.0f;
	for (int i = 0; i < MAX_FRAME_HISTORY; ++i)
	{
        averageFrameTime += frameTimes[i];
	}
    averageFrameTime /= MAX_FRAME_HISTORY;

    currentFps = 1.0f / averageFrameTime;
}

void Game::Mechanics::FPS::Stablize()
{
    accumulator -= deltaTime;
}

void Game::Mechanics::FPS::Cap()
{
    alpha = accumulator / deltaTime;
    if (accumulator > deltaTime)
	{
        accumulator = deltaTime;
	}
	else 
	{
        sleepTime = (deltaTime - accumulator) * 1000.0f;
        SDL_Delay(static_cast<Uint32>(sleepTime));
	}
}

bool Game::Mechanics::FPS::UpdateTick()
{
    return accumulator >= deltaTime;
}

int Game::Mechanics::FPS::GetFPS() const
{
    return currentFps;
}
