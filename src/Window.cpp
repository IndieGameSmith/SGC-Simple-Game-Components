/** 
 *  \file Window.cpp
 *  
 *  \brief Source file that Window related class.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-08
 */

#include "SDL2/SDL.h" 

#include "Window.hpp"
#include "Graphics_Exception.hpp"
 
Game::Graphics::Window :: Window()
{
    
}

Game::Graphics::Window :: Window(const char* p_title, int p_w, int p_h) : window(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if (window == nullptr)
    {
        std::string FailMessage = "Failed to create window: ";
        FailMessage.append(SDL_GetError());
        Game::Graphics::Exception::WindowCreationFailed(FailMessage.c_str());
    }
    
    SDL_GetWindowPosition(window, &windowPos.x, &windowPos.y);
    if (SDL_GetCurrentDisplayMode(0, &displayMode) < 0)
    {
        std::string FailMessage = "Failed to query display mode: ";
        FailMessage.append(SDL_GetError());
        Game::Graphics::Exception::QueryingDisplayModeFailed(FailMessage.c_str());
    }
}

void Game::Graphics::Window :: Create(const char* p_title, int p_w, int p_h)
{
    window = nullptr;
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if (window == nullptr)
    {
        std::string FailMessage = "Failed to create window: ";
        FailMessage.append(SDL_GetError());
        Game::Graphics::Exception::WindowCreationFailed(FailMessage.c_str());
    }
    
    SDL_GetWindowPosition(window, &windowPos.x, &windowPos.y);
    if (SDL_GetCurrentDisplayMode(0, &displayMode) < 0)
    {
        std::string FailMessage = "Failed to query display mode: ";
        FailMessage.append(SDL_GetError());
        Game::Graphics::Exception::QueryingDisplayModeFailed(FailMessage.c_str());
    }
}

SDL_DisplayMode Game::Graphics::Window :: CreateDisplayMode(int w, int h, int RefreshRate, Uint32 Format)
{
    SDL_DisplayMode mode;
    mode.w = w;
    mode.h = h;
    mode.refresh_rate = RefreshRate;
    mode.format = Format;
    return mode;
}
