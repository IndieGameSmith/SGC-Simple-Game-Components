/** 
 *  \file Window.cpp
 *  
 *  \brief Source file that Window related class.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-08
 */

#include "SDL2/SDL.h" 

#include "Graphics/Window.hpp"
#include "Utils/Exceptions/Graphics_Exception.hpp"
 
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

void Game::Graphics::Window :: SetDisplayMode(SDL_DisplayMode mode)
{
    SDL_SetWindowDisplayMode(window, &mode);
    Update();
}

void Game::Graphics::Window :: ResizeWindow(int w, int h)
{
    SDL_SetWindowSize(window, w, h);
}

void Game::Graphics::Window :: MoveWindowTo(int x, int y)
{
    SDL_SetWindowPosition(window, x, y);
}

void Game::Graphics::Window :: CenterWindow()
{
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void Game::Graphics::Window :: Restore()
{
    Uint32 flags = GetWindowFlags();
    if (flags & SDL_WINDOW_FULLSCREEN)
    {
        ToggleFullscreen();
    }
    
    CenterWindow();
    SetWindowResizable(true);
    RaiseWindow();
}

void Game::Graphics::Window :: SetWindowTitle(const char* p_title)
{
    SDL_SetWindowTitle(window, p_title);
}

void Game::Graphics::Window :: SetWindowIcon(SDL_Surface* icon)
{
    SDL_SetWindowIcon(window, icon);
}

void Game::Graphics::Window :: SetWindowResizable(bool resizable)
{
   SDL_bool resizableBool = SDL_FALSE;
   if (resizable)
   {
       resizableBool = SDL_TRUE;
   }
   
   SDL_SetWindowResizable(window, resizableBool);
}

void Game::Graphics::Window :: SetWindowOpacity(float opacity)
{
    SDL_SetWindowOpacity(window, opacity);
}

void Game::Graphics::Window :: SetWindowModal(bool modal)
{
    isWindowModal = modal;
}

void Game::Graphics::Window :: ToggleWindowVisiblity()
{
    Uint32 flags = GetWindowFlags();
    if (flags & SDL_WINDOW_SHOWN)
    {
        SDL_HideWindow(window);
    }
    else
    {
        SDL_ShowWindow(window);
    }
}

void Game::Graphics::Window :: ToggleFullscreen()
{
    Uint32 flags = GetWindowFlags();
    if (flags & SDL_WINDOW_FULLSCREEN)
    {
        SDL_SetWindowFullscreen(window, 0);
    }
    else
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    }
}

void Game::Graphics::Window :: ToggleBorder()
{
    Uint32 flags = GetWindowFlags();
    if (flags & SDL_WINDOW_BORDERLESS)
    {
        SDL_SetWindowBordered(window, SDL_TRUE);
    }
    else
    {
        SDL_SetWindowBordered(window, SDL_FALSE);
    }
}

void Game::Graphics::Window :: ToggleMaximize()
{
    Uint32 flags = GetWindowFlags();
    if (flags & SDL_WINDOW_MINIMIZED)
    {
        SDL_MaximizeWindow(window);
    }
}

void Game::Graphics::Window :: ToggleMinimize()
{
    Uint32 flags = GetWindowFlags();
    if (flags & SDL_WINDOW_MINIMIZED)
    {
        SDL_MinimizeWindow(window);
    }
}

void Game::Graphics::Window :: RaiseWindow()
{
    SDL_RaiseWindow(window);
}

void Game::Graphics::Window :: ShowMessageBox(const char* p_title, const char* message, MessageType messageType)
{
    switch(messageType)
    {
        case MessageType::ERROR:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, p_title, message, window);
            break;
        case MessageType::WARNING:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, p_title, message, window);
            break;
        case MessageType::INFORMATION:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, p_title, message, window);
            break;
        default:
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, p_title, message, window);
            break;
    }
}

void Game::Graphics::Window :: Update()
{
    SDL_GetWindowPosition(window, &windowPos.x, &windowPos.y);
    if (SDL_GetCurrentDisplayMode(0, &displayMode) < 0)
    {
        std::string FailMessage = "Failed to query display mode: ";
        FailMessage.append(SDL_GetError());
        Game::Graphics::Exception::QueryingDisplayModeFailed(FailMessage.c_str());
    }
}

SDL_Window* Game::Graphics::Window :: GetWindow() const 
{
    return window;
}

Uint32 Game::Graphics::Window :: GetWindowFlags() const
{
    return SDL_GetWindowFlags(window);
}

Game::Math::Point2D<int> Game::Graphics::Window :: GetWindowCenter() const
{
    Game::Math::Point2D<int> CentrePos, WindowSize;
    SDL_GetWindowSize(window, &WindowSize.x, &WindowSize.y);
    CentrePos.x = WindowSize.x / 2;
    CentrePos.y = WindowSize.y / 2;
    return CentrePos;
}

Game::Math::Pair<int, int> Game::Graphics::Window :: GetWindowSize() const
{
    Game::Math::Pair<int, int> WindowSize;
    SDL_GetWindowSize(window, &WindowSize.first, &WindowSize.second);
    return WindowSize;
}

SDL_DisplayMode Game::Graphics::Window ::GetCurrentDisplayMode() const
{
    int displayIndex = SDL_GetWindowDisplayIndex(0);
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(displayIndex, &mode);
    return mode;
}

SDL_DisplayMode Game::Graphics::Window ::GetDisplayMode(int displayIndex, int modeIndex) const
{
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, modeIndex, &mode);
    return mode;
}

Uint32 Game::Graphics::Window :: GetWindowFormat() const
{
    SDL_DisplayMode mode = GetCurrentDisplayMode();
    return mode.format;
}

int Game::Graphics::Window :: GetWindowDisplayIndex() const
{
    return SDL_GetWindowDisplayIndex(0);
}

int Game::Graphics::Window :: GetRefreshRate() const
{
    SDL_DisplayMode mode = GetCurrentDisplayMode();
    return mode.refresh_rate;
}

bool Game::Graphics::Window :: IsWindowOpen() const
{
    return SDL_GetWindowFlags(window) & SDL_WINDOW_SHOWN;
}

bool Game::Graphics::Window :: HasError() const
{
    return SDL_GetError() != nullptr;
}

const char* Game::Graphics::Window :: GetLastError() const
{
    return SDL_GetError();
}

void Game::Graphics::Window :: Destroy()
{
    SDL_DestroyWindow(window);
}
